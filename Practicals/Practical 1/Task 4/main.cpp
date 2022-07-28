#include <iostream>

/**
 * Function that takes an array and returns the number of elements in the array that are even.
 * @param array - Array To Search
 * @param size - Size of array
 * @return Number of Even Elements in Array
 */
int countEven(const int* array, int size){
    int n = 0;
    for(int i = 0; i < size; i++){
        if(*(array + i)%2==0){
            n++;
        }
    }

    return n;
}

/**
 * The maximum number in the provided array.
 * @param a - Array to Search
 * @param size - Size of array
 * @return Pointer to Maximum Number in Array
 */
double* maximum(double* a, int size){
    if(a == nullptr || size == 0) return nullptr;

    double* max = (a);
    for(int i = 0; i < size; i++){
        if(*(a + i) > *max){
            max = (a + i);
        }
    }
    return max;
}

int main (){
    //Array to be used in countEven() function
    int array1[10] = {1, 3, 6, 8, 10, 12, 54, 23, 66, 91};
    std::cout << "Array has " << countEven(array1, 10) <<  " even elements" << std::endl;

    //Array to be used in maximum() function
    double array2[10] = {1.32, 3.56, 6.1, 8.456, 10.32113, 12, 54.87, 23, 66.21, 91.88};
    std::cout << "Largest element: " << *maximum(array2, 10) << std::endl;

    return 0;
}