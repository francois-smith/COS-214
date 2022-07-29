#include <iostream>

/**
 * Function to print interval of input value -7 until it reaches a negative value and back up again.
 * @param n - Value Used In Recursion
 */
void recurse(int n)
{
    std::cout << n << ", ";
    if(n <= 0){
        return;
    }
    else{
        recurse(n-7);
        std::cout << n << ", ";
    }
}

/**
 * Implementation of the ackermann algorithm
 * @param val1 - First Number for the Calculation
 * @param val2 - Second Number for the Calculation
 * @return Result of the algorithm
 */
int A(int val1, int val2)
{
    if (val1 == 0){
        return val2 + 1;
    }
    else if((val1 > 0) && (val2 == 0)){
        return A(val1 - 1, 1);
    }
    else if((val1 > 0) && (val2 > 0)){
        return A(val1 - 1, A(val1, val2 - 1));
    }
}

int main()
{
    //Question 5.1: Bullet 1
    std::cout << "Input of 20:" << std::endl;
    recurse(20);
    std::cout << std::endl;

    //Question 5.1: Bullet 2
    std::cout << "Input of 14:" << std::endl;
    recurse(14);
    std::cout << std::endl;

    //Question 5.2
    std::cout << "Result of A(4, 2):" << std::endl;
    std::cout << A(4, 2) << std::endl;
    return 0;
}
