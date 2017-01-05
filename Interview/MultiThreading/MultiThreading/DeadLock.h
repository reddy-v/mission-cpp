#pragma once
#include <mutex>
#include <thread>
using namespace std;
class DeadLock
{
	mutex mu1;
	mutex mu2;

public:
	DeadLock();
	void DeadLockCaseF1();
	void DeadLockCaseF2();
	void DeadLockFixF1();
	void DeadLockFixF2();

	static void TestDeadLock();
	static void TestDeadLockFix();

	
	~DeadLock();
};

