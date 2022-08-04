#pragma once
#include "Enemy.h"
#include <string>

class EnemyFactory {
public:
    EnemyFactory() {}
    virtual ~EnemyFactory() {}
    virtual Enemy* createEnemy (std::string name) = 0;

protected:
    std::string getName();
};

