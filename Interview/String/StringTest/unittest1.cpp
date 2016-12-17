#include "stdafx.h"
#include "CppUnitTest.h"
#include "../String/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringTest
{		
	TEST_CLASS(StringCompression)
	{
	public:
		
		TEST_METHOD(SimpleTest)
		{
			StringCompression sc;
			Assert::AreEqual("xxx", sc.Soution1("aaa"));
		}

	};
}