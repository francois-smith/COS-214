/*
 * Enemy.h
 *
 *  Created on: 02 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "SquadMember.h"
#include "EnemyState.h"
#include "EnemyMemento.h"
#include <iostream>

/**
 * Abstract class for all enemy types. \n
 * Defines a base attack function that follows the same logic for all enemies.
 */
class Enemy
{
public:
    //Constructor and Destructor
    Enemy(int hp, int dmg, std::string& atk, std::string& name, std::string& def);
    virtual ~Enemy();

    //Template Method
    void attack(SquadMember* z);

    //Setters and Getters
    int getHP() const;
    void setHP(int newHp);

    int getDmg() const;
    void setDamage(int newDmg);

    std::string getName() const;
    void setName(std::string& newName);

    std::string getAtk() const;
    void setAtk(std::string& newAtk);

    std::string getDef() const;
    void setDef(std::string& newDef);

    //Helper Functions
    void print() const;

    //Memento Functions
    void loadSave(EnemyMemento* const save);
    EnemyMemento* saveGame();

protected:
    //Template Functions
    /**
     * The enemy hits the squad member by calling the SquadMember's takeDamage method,
     * this method takes the damage done by the enemy as a parameter.
     * @param z - SquadMember to Attack
     * @return true if the squad member is killed, false otherwise
     */
    virtual bool hitSquadMember(SquadMember* z) = 0;

    /**
     * Called when SquadMember is still alive after being hit by an enemy. \n
     * Damages the current enemy by retrieving the squad members damage value. The value is then subtracted from the current enemy's HP.
     * @param z - SquadMember Attacking
     * @return if the enemy is killed
     */
    virtual bool getHit(SquadMember* z) = 0;

    /**
     * Generic function that is called when the enemy is killed. Outputs a celebratory message.
     */
    virtual void celebrate() = 0;

    /**
     * If SquadMember kills an enemy a death message is outputted
     */
    virtual void die() = 0;

private:
    //Private Functions
    EnemyState* genState();

    //Member Variables
    int hp;
    int dmg;
    std::string atk;
    std::string def;
    std::string name;
    EnemyState* state;
};
