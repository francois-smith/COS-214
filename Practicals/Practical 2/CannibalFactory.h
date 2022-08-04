#pragma once
#include "EnemyFactory.h"

class CannibalFactory: public EnemyFactory {
public:
    Enemy* createEnemy (std::string attack, std::string defense) override;
};
