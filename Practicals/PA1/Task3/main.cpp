#include "calculator.h"
#include <iostream>
#include <iomanip>

int main(){
    Calculator<float> calculator(22.45, 12.22);
    int x = calculator.add();
    std::cout << std::setprecision(10) << x << std::endl;
    return 0;
}