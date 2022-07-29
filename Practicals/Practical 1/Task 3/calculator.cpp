#pragma once
#include "calculator.h"

/**
 * Constructor for calculator object
 * @tparam T - Generic Type of the Calculator
 * @param n1 - First Number To Use in Calculations
 * @param n2 - Second Number To Use in Calculations
 */
template <class T>
Calculator<T>::Calculator(T n1, T n2)
{
    this->num1 = n1;
    this->num2 = n2;
}

/**
 * Adds the numbers stored in the calculator
 * @tparam T - Generic Type of the Calculator
 * @return Result of the Addition
 */
template <class T>
T Calculator<T>::add()
{
    return this->num1 + this->num2;
}

/**
 * Subtracts the numbers stored in the calculator
 * @tparam T - Generic Type of the Calculator
 * @return Result of the Subtraction
 */
template <class T>
T Calculator<T>::subtract()
{
    return this->num1 - this->num2;
}

/**
 * Multiplies the numbers stored in the calculator
 * @tparam T - Generic Type of the Calculator
 * @return Result of the Multiplication
 */
template <class T>
T Calculator<T>::multiply()
{
    return this->num1 * this->num2;
}

/**
 * Divides the numbers stored in the calculator
 * @tparam T - Generic Type of the Calculator
 * @return Result of the Division
 */
template <class T>
T Calculator<T>::divide()
{
    return this->num1 / this->num2;
}