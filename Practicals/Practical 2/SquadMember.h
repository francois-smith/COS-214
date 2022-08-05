/*
 * SquadMember.h
 *
 *  Created on: 05 Aug 2022
 *      Author: Francois Smith
 */

#pragma once
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
    //s and Destructor
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
     * Virtual clone method implemented within sub SquadMember classes.
     * @return - Pointer to a new SquadMember object.
     */
    virtual SquadMember* clone() = 0;
    virtual std::string generateName();

    //Helper Function
    void printStats() const;

private:
    //Member Variables
    std::string type;
    std::string name;
    int dmg;
    int hp;
};
