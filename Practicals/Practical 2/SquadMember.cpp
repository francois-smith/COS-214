/*
 * SquadMember.cpp
 *
 *  Created on: 05 Aug 2022
 *      Author: Francois Smith
 */

#include "SquadMember.h"

SquadMember::SquadMember(int hp, int dmg)
{
    this->hp = hp;
    this->dmg = dmg;
}

SquadMember::SquadMember(int hp, int dmg, std::string& name) {
    this->hp = hp;
    this->dmg = dmg;
    this->name = name;
}

/**
 * Returns the current Damage value of the enemy.
 * @return Current Damage value.
*/
int SquadMember::getDmg() const
{
    return this->dmg;
}

/**
 * Sets the new Damage value of the SquadMember.
 * @param newDmg - New Damage Value
 */
void SquadMember::setDmg(int newDmg)
{
    this->dmg = newDmg;
}

/**
 * Sets the new HP value of the SquadMember.
 * @param newHp - New HP Value
 */
void SquadMember::setHP(int newHp)
{
    this->hp = newHp;
}

/**
 * Sets the new name of the SquadMember.
 * @param newName - New Name
 */
void SquadMember::setName(std::string& newName)
{
    this->name = newName;
}

/**
 * Returns the current name of the SquadMember.
 * @return Current name
*/
std::string SquadMember::getName() const
{
    return this->name;
}

/**
 * Returns the current HP value of the SquadMember.
 * @return Current HP value.
*/
int SquadMember::getHP() const
{
    return this->hp;
}

/**
 * Returns the type of SquadMember.
 * @return Type.
*/
std::string SquadMember::getType() const
{
    return this->type;
}

/**
 * Sets type of SquadMember.
 * @param newType - New Type
*/
void SquadMember::setType(std::string &newType)
{
    this->type = newType;
}

/**
 * Outputs death message when a SquadMember is killed. \n
 * Clears memory used by SquadMember object.
 */
void SquadMember::die() const
{
    std::cout << "SquadMember " << this->getName() << " has died." << std::endl;
}

/**
 * Damages the current SquadMember by subtracting the damage value of the enemy from the current HP value. \n
 * @param damage - Damage Value of Enemy
 * @return If the SquadMember is killed
 */
int SquadMember::takeDamage(int damage)
{
    setHP(this->hp - damage);
    return this->hp;
}

/**
 * Generates a random name for a SquadMember.
 * @return Generated Name
 */
std::string SquadMember::generateName() {
    return "SquadMember";
}



/**
 * Prints the SquadMember's name, Damage and HP. Used for debugging.
 * @return Debug Message
 */
void SquadMember::printStats() const
{
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Type: " << this->getType() << " | HP: " << this->getHP() << " | DMG: " << this->getDmg() << std::endl;
    std::cout << "------------------------------------------" << std::endl << std::endl;
}