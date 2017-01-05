#include "stdafx.h"
#include "DeadLock.h"
#include <vector>
#include <iostream>

DeadLock::DeadLock()
{
}

void DeadLock::DeadLockCaseF1()
{
	std::lock_guard<mutex> lck1(mu1);
	int cnt = 0;
	for (int i = 1; i < 1000; i++) { cnt++; }
	std::lock_guard<mutex> lck2(mu2);
	for (int i = 1; i < 1000; i++) { cnt++; }
}

void DeadLock::DeadLockCaseF2()
{
	std::lock_guard<mutex> lck2(mu2);
	int cnt = 0;
	for (int i = 1; i < 1000; i++) { cnt++; }
	std::lock_guard<mutex> lck1(mu1);
	for (int i = 1; i < 1000; i++) { cnt++; }
}

void DeadLock::DeadLockFixF1()
{
	std::unique_lock<mutex> lck2(mu2,defer_lock);
	int cnt = 0;
	for (int i = 1; i < 1000; i++) { cnt++; }
	std::unique_lock<mutex> lck1(mu1, defer_lock);
	for (int i = 1; i < 1000; i++) { cnt++; }
	lock(lck1, lck2);
}

void DeadLock::DeadLockFixF2()
{
	std::unique_lock<mutex> lck2(mu1, defer_lock);
	int cnt = 0;
	for (int i = 1; i < 1000; i++) { cnt++; }
	std::unique_lock<mutex> lck1(mu2, defer_lock);
	for (int i = 1; i < 1000; i++) { cnt++; }
	lock(lck1, lck2);
}
void DeadLock::TestDeadLock()
{
	vector<thread> v;
	DeadLock dl;
	for (int i = 0; i < 3; i++)
		v.emplace_back(&DeadLock::DeadLockCaseF1, &dl);
	for (int i = 3; i < 6; i++)
		v.emplace_back(&DeadLock::DeadLockCaseF2, &dl);
	for (int i = 0; i < 6; i++)
		v[i].join();
}

void DeadLock::TestDeadLockFix()
{
	vector<thread> v;
	DeadLock dl;
	for (int i = 0; i < 3; i++)
		v.emplace_back(&DeadLock::DeadLockFixF1, &dl);
	for (int i = 3; i < 6; i++)
		v.emplace_back(&DeadLock::DeadLockFixF2, &dl);
	for (int i = 0; i < 6; i++)
		v[i].join();
}

DeadLock::~DeadLock()
{
}
