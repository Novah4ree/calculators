#pragma once
#include "wx/wx.h"

class CalculatorProcessor
{
private:
	
	static CalculatorProcessor* instance;
	
public:
	static CalculatorProcessor* GetInstance();
	double Calculate(const std::string& expression);
	int getPrecedence(const std::string& op);
	~CalculatorProcessor();
};

