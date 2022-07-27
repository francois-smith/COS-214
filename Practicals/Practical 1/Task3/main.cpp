#include "calculator.h"
#include <iostream>
#include <string>

int main(){
    double value1, value2;
    

    char c [10];
    const int* e = ( const int *) 522 ;
    c [10] = *&*e;

    //Getting 2 numbers
    std::cout << "Enter your first value:" << std::endl;
    std::cin >> value1;
    std::cout << "Enter your second value:" << std::endl;
    std::cin >> value2;

    //Initiate template object of type double
    Calculator<double> calculator(value1, value2);

    std::cout << "Addition of values = " << calculator.add() << std::endl;
    std::cout << "Subtraction of values = " << calculator.subtract() << std::endl;
    std::cout << "Multiplication of values = " << calculator.multiply() << std::endl;
    std::cout << "Division of values = " << calculator.divide() << std::endl;
    return 0;
}