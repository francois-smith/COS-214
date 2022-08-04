#pragma once
#include "EnemyFactory.h"

class SnakeFactory: public EnemyFactory {
public:
    Enemy* createEnemy (std::string attack, std::string defense) override;
};
