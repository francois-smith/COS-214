#pragma once
#include "EnemyFactory.h"

class GorillaFactory: public EnemyFactory {
public:
    Enemy* createEnemy (std::string attack, std::string defense) override;
};
