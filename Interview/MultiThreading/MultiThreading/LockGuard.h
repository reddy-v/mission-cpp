#pragma once
#include <thread>
#include <mutex>
#include <iostream>
using namespace std;
class LockGuard
{
	mutex mu;
public:
	void LockGuardPrint()
	{
		int cnt = 0;
		for (int i = 0; i < 1000000; ++i) {
			std::lock_guard<mutex> lck(mu); // wrong way of doing it, just for representatio purpose
			cnt++;
		}
	}
	void UniqueLockPrint()
	{
		std::unique_lock<mutex> lck(mu, defer_lock);
		int cnt = 0;
		for (int i = 0; i < 1000000; ++i) {
			 // wrong way of doing it, just for representatio purpose
			lck.lock();
			cnt++;
			lck.unlock();
		}
	}
	static void LockGuardPrintTest();
	static void UniqueLockPrintTest();

	LockGuard();
	~LockGuard();
};

