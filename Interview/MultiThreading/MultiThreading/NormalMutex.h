#pragma once
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
class NormalMutex
{
	mutex mu;
public:
	NormalMutex();
	inline void print() const
	{
		int cnt = 50;
		while (cnt-- > 0) {
			cout << this_thread::get_id();
			cout << "Hell0" << endl;
		}
	}

	inline void MutexProtectedprint()
	{
		int cnt = 50;
		while (cnt-- > 0) {
			mu.lock();
			cout << this_thread::get_id();
			cout << "Hell0" << endl;
			mu.unlock();
		}
	}

	static void Test();
	static void MutexTest();
	~NormalMutex();
};

