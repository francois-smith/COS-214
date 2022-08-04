#include "JaguarFactory.h"
#include "Jaguar.h"

Enemy *JaguarFactory::createEnemy(std::string attack, std::string defense) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(10.0,3.0);
    std::string name = this->getName();
    return new Jaguar(distribution(generator), 6, attack, name, defense);
}