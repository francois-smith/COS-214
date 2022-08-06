/*
 * SquadMember.h
 *
 *  Created on: 05 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
#include "SquadMemberState.h"
#include <iostream>
#include <string>
#include <random>

/**
 * Abstract class for all SquadMember types. \n
 * Contains base functionality needed by all SquadMembers, contains abstract methods for cloning to implement the prototype pattern.
 */
class SquadMember
{
public:
    //Constructors and Destructor
    SquadMember() = default;
    SquadMember(int hp, int dmg);
    SquadMember(int hp, int dmg, std::string& name);
    virtual ~SquadMember() = default;

    //Getters and Setters
    int getDmg() const;
    void setDmg(int newDmg);

    int getHP() const;
    void setHP(int newHp);

    std::string getType() const;
    void setType(std::string& newType);

    std::string getName() const;
    void setName(std::string& newName);

    //Member Functions
    int takeDamage(int damage);
    void die() const;

    //Template and Prototype Functions
    /**
     * @brief Virtual clone method implemented within derived SquadMember classes.
     * @return - Pointer to a new SquadMember object.
     */
    virtual SquadMember* clone() = 0;
    virtual std::string generateName();

    //Helper Function
    void printStats() const;

    //Memento Functions
    void loadSave(SquadMemberState* const save);
    SquadMemberState* saveGame();

private:
    //Member Variables
    std::string type;
    std::string name;
    int dmg;
    int hp;
    SquadMemberState* state;
};
