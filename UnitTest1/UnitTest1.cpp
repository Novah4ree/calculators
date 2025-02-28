#include "../CalculatorProcessor.h"
#include "CppUnitTest.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorProcessors
{
	TEST_CLASS(CalculatorProcessorTest)
	{
	public:
		
		TEST_METHOD(TestAddition)
		{
			double result = CalculatorProcessor::GetInstance()->Calculate("2+2");
			Assert::AreEqual(4.0, result);
		}
		TEST_METHOD(TestSubstraction) {
			double result = CalculatorProcessor::GetInstance()->Calculate("50-40");
			Assert::AreEqual(10.0, result);

		}
		TEST_METHOD(TestMultiplication) {
			double result = CalculatorProcessor::GetInstance()->Calculate("5*5");
			Assert::AreEqual(25.0, result);

		}
		TEST_METHOD(TestDivision) {
			double result = CalculatorProcessor::GetInstance()->Calculate("100/10");
			Assert::AreEqual(10.0, result);
		}
		TEST_METHOD(TestModulo) {
			double result = CalculatorProcessor::GetInstance()->Calculate("150%5");
			Assert::AreEqual(7.5, result);
		}
		TEST_METHOD(TestAdditionMultiplication) {
			double result = CalculatorProcessor::GetInstance()->Calculate("3+5*2");
			Assert::AreEqual(13.0, result);
		}
		TEST_METHOD(TestSubstractionandDivision) {
			double result = CalculatorProcessor::GetInstance()->Calculate("100-25/5");
			Assert::AreEqual(95.0, result);
		}
		TEST_METHOD(TestSin) {

			double result = CalculatorProcessor::GetInstance()->Calculate("sin 180");
				Assert::AreEqual(0, result, 0);
		}
		TEST_METHOD(TestCos) {

			double result = CalculatorProcessor::GetInstance()->Calculate("cos 123");
				Assert::AreEqual(0.95, result, 1);
		}
		TEST_METHOD(TestTan) {

			double result = CalculatorProcessor::GetInstance()->Calculate("tan 85 ");
				Assert::AreEqual(0.18, result, 0.01);
		}

	};
}
