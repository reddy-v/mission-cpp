#pragma once
#include <iostream>
#include <thread>
using namespace std;

std::once_flag flag1, flag2;

inline void simple_do_once()
{
	std::call_once(flag1, []() { std::cout << "Simple example: called once\n"; });
}

inline void may_throw_function(bool do_throw)
{
	if (do_throw) {
		std::cout << "throw: call_once will retry\n"; // this may appear more than once
		throw std::exception();
	}
	std::cout << "Didn't throw, call_once will not attempt again\n"; // guaranteed once
}

inline void do_once(bool do_throw)
{
	try {
		std::call_once(flag2, may_throw_function, do_throw);
	}
	catch (...) {
	}
}

class calling_once
{
	static auto_ptr<calling_once> instance;
	static once_flag oc;
	static void InitiateUtil()
	{
		try
		{
			instance.reset(new calling_once);
		}
		catch(...)
		{
			cout << "Trying Again" << endl;
		}
	}
	calling_once() {}
public :

	static auto_ptr<calling_once> Initiate()
	{
		call_once(oc, &calling_once::InitiateUtil);
		return instance;
	}
	static void print()
	{
		cout << "Printing .." << endl;
	}
	~calling_once() { }

};

once_flag calling_once::oc;
auto_ptr<calling_once> calling_once::instance(nullptr);
