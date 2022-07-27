#pragma once
#include <iostream>

class ClassA{
public:
    ClassA(){
        std::cout << "ClassA's Empty Constructor is Called" << std::endl;
    };

    virtual ~ClassA(){
        std::cout << "ClassA's Destructor is Called" << std::endl;
    };
};

class ClassB{
public:
    ClassB(){
        std::cout << "ClassB's Empty Constructor is Called" << std::endl;
    };

    virtual ~ClassB(){
        std::cout << "ClassB's Destructor is Called" << std::endl;
    };
};

class ClassC: public ClassA{
public:
    ClassC(){
        std::cout << "ClassC's Empty Constructor is Called" << std::endl;
    };

    virtual ~ClassC(){
        std::cout << "ClassC's Destructor is Called" << std::endl;
    };
};

class ClassD: public ClassA, public ClassB{
public:
    ClassD(){
        std::cout << "ClassD's Empty Constructor is Called" << std::endl;
    };

    virtual ~ClassD(){
        std::cout << "ClassD's Destructor is Called" << std::endl;
    };
};
