#include "stdafx.h"
#include "NormalMutex.h"
#include <vector>
using namespace std;

NormalMutex::NormalMutex()
{

}


void NormalMutex::Test()
{
	auto maxthreads = thread::hardware_concurrency();
	{
		vector<thread> v;
		NormalMutex nm;
		for (auto i = 0; i < maxthreads; i++)
			v.emplace_back(thread(&NormalMutex::print,&nm));
		for (auto i = 0; i < maxthreads; i++)
			v[i].join();
	}
}

void NormalMutex::MutexTest()
{
	auto maxthreads = thread::hardware_concurrency();
	{
		vector<thread> v;
		NormalMutex nm;

		for (auto i = 0; i < maxthreads; i++)
			v.emplace_back(thread(&NormalMutex::MutexProtectedprint, &nm));
		for (auto i = 0; i < maxthreads; i++)
			v[i].join();
	}
}

NormalMutex::~NormalMutex()
{
}
