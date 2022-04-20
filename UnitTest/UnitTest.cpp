#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab12_4.1\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string text = "asfasfsa\nasdnonfd\nn oasfasf";
			Assert::IsTrue(find(text, 2, 1));
		}
	};
}
