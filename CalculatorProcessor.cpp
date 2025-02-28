#include <wx/string.h>
#include "CalculatorProcessor.h"
#include <vector>
#include <stdexcept>
#include <stack>
#include <cmath>
#include <sstream>
#include <algorithm>
#include "Windows.h"

//initialized singleton instance
CalculatorProcessor* CalculatorProcessor::instance = nullptr;
//singleton pattern 
CalculatorProcessor* CalculatorProcessor::GetInstance()
{
    if (CalculatorProcessor::instance == nullptr) {
       instance = new CalculatorProcessor();
    }
    return instance;
}

//destructor
CalculatorProcessor::~CalculatorProcessor() {}
//main calculator method
double CalculatorProcessor::Calculate(const std::string& expression)
{    //wxString to string
    std::string m_string = expression;
    std::stack<double>  valuestack;
    if (m_string.empty()) {
        return 0.0;
    }
    //add spacing around operators for tokenization
    for (size_t i = 0; i < m_string.length(); ++i)
    {
        if (m_string[i] == '+' || m_string[i] == '-' || m_string[i] == '*' || m_string[i] == '/' || m_string[i] == '%') {
            m_string.insert(i, " ");
            m_string.insert(i + 2, " ");
            i += 2;
        }
        
    }
   //tokenization
    std::istringstream _StringStream(m_string);
    std::vector<std::string> _tokens;
    std::string _CurrToken;
    //process each token
    while (_StringStream >> _CurrToken) {
        //erase all extra spacing
        _CurrToken.erase(remove(_CurrToken.begin(), _CurrToken.end(), ' '), _CurrToken.end());
        if (!_CurrToken.empty()) {
            _tokens.push_back(_CurrToken);
        }
    }
    //converting to postfix using shunting yard algorithm
    std::vector<std::string> postfix;
    std::stack<std::string> _operatorStack;

    for (const std::string& _token : _tokens) {
        //trig functions handle
        if (_token == "sin" || _token == "cos" || _token == "tan") {
            _operatorStack.push(_token);
        }
        //handle operations
        else if (_token == "+" || _token == "-" || _token == "*" || _token == "/" || _token == "%") {
            //operators according to precedence
            while (!_operatorStack.empty() && getPrecedence(_operatorStack.top()) >= getPrecedence(_token)) {
                postfix.push_back(_operatorStack.top());
                _operatorStack.pop();
            }

            _operatorStack.push(_token);
        }// handle numbers
        else {
            postfix.push_back(_token);
        }
        
    }//emptying the remaining operators to postfix
    while (!_operatorStack.empty()) {
        postfix.push_back(_operatorStack.top());
        _operatorStack.pop();
    }
    std::stack<double>value = valuestack;


    for (const std::string& token : postfix) {
        //process trigg functions
        if (token == "sin" || token == "cos" || token == "tan") {
            if (valuestack.empty()) throw std::runtime_error("Invalid expression");
            double value = valuestack.top();
            valuestack.pop();
            if (token == "sin") {
                valuestack.push(sin(value));
            }
            else if (token == "cos") {
                valuestack.push(cos(value));
            }
            else if (token == "tan") {
                valuestack.push(tan(value));
            }
        }
        //operator process
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {

            if (_tokens.size() == 3) {
                double a = std::stod(_tokens[0]);
                double b = std::stod(_tokens[2]);

                std::string oper = _tokens[1];
                if (oper == "+") {
                    valuestack.push(a + b);
                }
                else if (oper == "-") {
                    valuestack.push(a - b);
                }
                else if (oper == "*") {
                    valuestack.push(a * b);
                }
                else if (oper == "/") {
                    if (b == 0) {
                        throw std::runtime_error("Division by Zero");
                        valuestack.push(a / b);
                    }
                   
                }
                else if (oper == "%") {
                       if (b == 0) {
                        throw std::runtime_error("Modulo by zero");
                         valuestack.push(fmod(a, b));
                       }
                  
                }
            }
        }   
        //process numbers
        else {
            
         valuestack.push(std::stod(token));//convert to double
            
        }
       
    }
    
    return valuestack.empty() ? 0.0 : valuestack.top();//final return result
}
//define operator precedence
int CalculatorProcessor::getPrecedence(const std::string& op)
{
    if (op == "sin" || op == "cos" || op == "tan") {
        return 4; // highest
    }
    else if (op == "*" || op == "/" || op == "%") {
        return 3;//second
    }
    else if (op == "+" || op == "-") {
        return 2;//third
    }
    else {
        return 0;//lowest
    }
}


