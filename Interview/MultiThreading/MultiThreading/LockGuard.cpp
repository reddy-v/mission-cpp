#include "stdafx.h"
#include "LockGuard.h"
#include <vector>


void LockGuard::LockGuardPrintTest()
{
	vector<thread> v;
	auto maxt = thread::hardware_concurrency();
	LockGuard lg;
	for (int i = 0; i < maxt; ++i)
	{
		v.emplace_back(thread(&LockGuard::LockGuardPrint, &lg));
	}
	for (int i = 0; i < maxt; ++i) { v[i].join(); }
}

void LockGuard::UniqueLockPrintTest()
{
	vector<thread> v;
	auto maxt = thread::hardware_concurrency();
	LockGuard lg;
	for (int i = 0; i < maxt; ++i)
	{
		v.emplace_back(thread(&LockGuard::UniqueLockPrint, &lg));
	}
	for (int i = 0; i < maxt; ++i) { v[i].join(); }
}

LockGuard::LockGuard()
{
}


LockGuard::~LockGuard()
{
}
