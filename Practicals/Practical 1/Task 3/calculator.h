#pragma once

/**
 * Generic calculator class
 * @tparam T - Generic Type
 */
template <class T>
class Calculator
{
private:
    T num1 , num2;
    
public:
    Calculator(T n1, T n2);
    T add();
    T subtract();
    T multiply();
    T divide();
};

#include "calculator.cpp"