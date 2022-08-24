//
// Created by Francois Smith on 2022/08/24.
//

#pragma once
#include <random>
#include <chrono>
#include <string>

//State Design Pattern Imports
#include "BattleState.h"
#include "AgileBattleState.h"
#include "NormalBattleState.h"
#include "StrongBattleState.h"

//Strategy Design Pattern Imports
#include "PlayStyle.h"

class Pokemon
{
public:
    Pokemon(std::string name, int damage, int HP, PlayStyle* playStyle);
    int selectBattleState();
    int attack();
    void setPlayStyle(PlayStyle* newPlayStyle);
    void takeDamage(int damage);
    ~Pokemon();
    void print();
    bool isAlive();

private:
    BattleState* battleState;
    PlayStyle* playStyle;
    std::string name;
    int HP;
    int damage;
};
