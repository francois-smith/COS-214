#include "main.h"

int main()
{
    std::cout << "Creating ClassA" << std::endl;
    ClassA* a = new ClassA();
    std::cout << "" << std::endl;

    std::cout << "Creating ClassB" << std::endl;
    ClassB* b = new ClassB();
    std::cout << "" << std::endl;

    std::cout << "Creating ClassC" << std::endl;
    ClassC* c = new ClassC();
    std::cout << "" << std::endl;

    std::cout << "Creating ClassD" << std::endl;
    ClassD* d = new ClassD();
    std::cout << "" << std::endl;

    std::cout << "Creating ClassE" << std::endl;
    ClassE* e = new ClassE();
    std::cout << "" << std::endl;

    std::cout << "Destructing Classes" << std::endl;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;

    return 0;
}