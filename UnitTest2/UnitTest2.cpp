#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_2rec/Lab_08_2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest82Rec
{
	TEST_CLASS(UnitTest82Rec)
	{
	public:
		TEST_METHOD(TestRemoveSpaces)
		{
			char str[100] = "Hello  , world   !";
			char dest[100];
			RemoveSpaces(dest, str);
			Assert::AreEqual("Hello, world!", dest);
		}
	};
}