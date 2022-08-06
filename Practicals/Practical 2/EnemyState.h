/*
 * EnemyState.h
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include <string>

/**
 * EnemyState class. Contains all values that need to be saved for an enemy.
 */
class EnemyState
{
private:
    int hp;
    int dmg;
    std::string atk;
    std::string def;
    std::string name;

public:
    //Constructor and Destructor
    EnemyState(int hp, int dmg, std::string& atk, std::string& def, std::string& name);
    ~EnemyState() = default;

    //Getters
    int getHp() const;
    int getDmg() const;
    std::string getAtk() const;
    std::string getDef() const;
    std::string getName() const;
};
