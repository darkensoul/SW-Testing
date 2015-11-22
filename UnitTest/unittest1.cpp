#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Student.h"
#include "../Students.h"
#include "../fileIO.h" // required


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			fileIO woo;
			Student student;
			Students students;
					
			// TODO: Your test code here

			Assert::AreEqual(1, 1);
		}

	};
}