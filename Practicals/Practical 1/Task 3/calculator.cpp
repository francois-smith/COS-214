#pragma once
#include "calculator.h"

template <class T>
Calculator<T>::Calculator(T n1, T n2){
    this->num1 = n1;
    this->num2 = n2;
}

template <class T>
T Calculator<T>::add(){
    return this->num1 + this->num2;
}

template <class T>

T Calculator<T>::subtract(){
    return this->num1 - this->num2;
}

template <class T>
T Calculator<T>::multiply(){
    return this->num1 * this->num2;
}

template <class T>
T Calculator<T>::divide(){
    return this->num1 / this->num2;
}