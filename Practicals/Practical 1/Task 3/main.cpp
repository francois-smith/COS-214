#include "calculator.h"
#include <iostream>
#include <string>

int main()
{
    //Question 3.2
    std::cout << "Question 3.2: " << std::endl;
    Calculator<int> two(741, 13);
    std::cout << "Division value: " << two.divide() << std::endl;
    std::cout << std::endl;

    //Question 3.3
    std::cout << "Question 3.3: " << std::endl;
    Calculator<float> three(127.58, 54.971);
    std::cout << "Addition value: " << three.add() << std::endl;
    std::cout << std::endl;

    //Question 3.4
    std::cout << "Question 3.4: " << std::endl;
    Calculator<std::string> four("Hello ", "World!");
    std::cout << "Addition value: " << four.add() << std::endl;
    std::cout << std::endl;

    //Question 3.5
    std::cout << "Question 3.5: " << std::endl;
    std::cout << "Strings cannot be multiplied." << std::endl;

    return 0;
}