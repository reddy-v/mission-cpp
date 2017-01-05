// MultiThreading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NormalMutex.h"
#include "LockGuard.h"
#include "DeadLock.h"
#include "call_once.h"
#include <chrono>
#include <string>

struct timer
{
	const std::chrono::time_point<std::chrono::steady_clock> tm{ chrono::steady_clock::now() };
	timer(string str)
	{
		cout << "Starting Timer " << str << endl;
	}
	~timer()
	{
		cout << "Time Lapsed " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - tm).count() << endl;
	}
	
};

int main()
{
	std::thread st1(simple_do_once);
	std::thread st2(simple_do_once);
	std::thread st3(simple_do_once);
	std::thread st4(simple_do_once);
	st1.join();
	st2.join();
	st3.join();
	st4.join();

	std::thread t1(do_once, true);
	std::thread t2(do_once, true);
	std::thread t3(do_once, false);
	std::thread t4(do_once, true);
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	std::thread t11(&calling_once::Initiate);
	std::thread t21(&calling_once::Initiate);
	std::thread t31(&calling_once::Initiate);
	std::thread t41(&calling_once::Initiate);
	t11.join();
	t21.join();
	t31.join();
	t41.join();
}

