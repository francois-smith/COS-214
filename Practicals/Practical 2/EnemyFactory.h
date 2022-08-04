#pragma once
#include "Enemy.h"
#include <ctime>
#include <string>
#include <random>

class EnemyFactory {
public:
    EnemyFactory() {}
    virtual ~EnemyFactory() {}
    virtual Enemy* createEnemy(std::string attack, std::string defense) = 0;

protected:
    std::string getName();
};

