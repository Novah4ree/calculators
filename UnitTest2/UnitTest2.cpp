#include "../ButtonFactory.h"
#include "CppUnitTest.h"


#define _CRT_SECURE_NO_WARNINGS

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ButtonFactorysTest
{
	TEST_CLASS(ButtonFactoryTests)
	{
	public:
		
		TEST_METHOD(TestCreateBtn)
		{
			wxButton* button = ButtonFactory::CreateBtn(nullptr, 10026, "Test", wxDefaultPosition, wxDefaultSize);
			Assert::IsNotNull(button);

		}
		TEST_METHOD(TestCreateNumberBtn)
		{
			wxButton* button = ButtonFactory::CreateNumberBtn(nullptr, 10007, "7", wxDefaultPosition, wxDefaultSize);
			Assert::IsNotNull(button);

		}
		TEST_METHOD(TestCreateOperationBtn)
		{
			wxButton* button = ButtonFactory::CreateOperationBtn(nullptr, 10015, "+", wxDefaultPosition, wxDefaultSize);
			Assert::IsNotNull(button);

		}
		TEST_METHOD(TestCreateFunctionBtn)
		{
			wxButton* button = ButtonFactory::CreateFunctionBtn(nullptr, 10020, "sin", wxDefaultPosition, wxDefaultSize);
			Assert::IsNotNull(button);

		}
		TEST_METHOD(TestCreateClearBtn)
		{
			wxButton* button = ButtonFactory::CreateClearBtn(nullptr, 10011, "C", wxDefaultPosition, wxDefaultSize);
			Assert::IsNotNull(button);

		}

		TEST_METHOD(TestCreateBackSpaceBtn)
		{
			wxButton* button = ButtonFactory::CreateBackSpaceBtn(nullptr, 10012, "<-", wxDefaultPosition, wxDefaultSize);
			Assert::IsNotNull(button);

		}
		TEST_METHOD(TestCreateEqualBtn)
		{
			wxButton* button = ButtonFactory::CreateEqualBtn(nullptr, 10010, "=", wxDefaultPosition, wxDefaultSize);
			Assert::IsNotNull(button);

		}
		
	};
}
