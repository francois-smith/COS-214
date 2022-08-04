#pragma once
#include "EnemyFactory.h"

class JaguarFactory: public EnemyFactory {
public:
    Enemy* createEnemy (std::string attack, std::string defense) override;
};