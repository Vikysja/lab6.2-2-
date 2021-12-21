#include "pch.h"
#include "CppUnitTest.h"
#include "../6,2(2)/6,2(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest622
{
	TEST_CLASS(UnitTest622)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 10;
			int a[size];
			Create(a, size, 10, 0);
			int s = arraySize(a);
			Assert::AreEqual(size, s, 0.01);
		}
	};
}
