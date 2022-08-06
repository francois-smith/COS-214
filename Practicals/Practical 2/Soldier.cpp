/*
 * Soldier.cpp
 *
 *  Created on: 05 Aug 2022
 *      Author: Francois Smith
 */

#include "Soldier.h"

/**
 * @brief Base constructor class for Soldier, generates random name, damage and hp values.
 */
Soldier::Soldier()
{
    //Set Type
    std::string type = "Soldier";
    this->setType(type);

    //Generate random name
    std::string soldierName = this->generateName();
    this->setName(soldierName);

    //Create random number generators
    std::random_device seeder;
    std::mt19937 generator(seeder());
    std::uniform_int_distribution<int> health(5,9);
    std::uniform_int_distribution<int> damage(2,8);

    //Generate random values for hp and dmg
    this->setHP(health(generator));
    this->setDmg(damage(generator));
}

/**
 * @brief Constructor for the Soldier class. Defines Damage and HP values. \n
 * @brief Used in clone method to create an exact copy of the Soldier except for name field.
 * @param hp - HP of Soldier
 * @param dmg - Damage of Soldier
 */
Soldier::Soldier(int hp, int dmg): SquadMember(hp, dmg)
{
    //Set Type
    std::string type = "Soldier";
    this->setType(type);
}

/**
 * @brief Constructor for the Soldier class. Defines Damage, HP and name values. \n
 * @brief Used when constructing a specific Soldier with pre set stats and name.
 * @param hp - HP of Soldier
 * @param dmg - Damage of Soldier
 * @param name - Name of Soldier
 */
Soldier::Soldier(int hp, int dmg, std::string &name) : SquadMember(hp, dmg, name)
{
    //Set Type
    std::string type = "Soldier";
    this->setType(type);
}

SquadMember *Soldier::clone()
{
    //Generate a random name for the new Soldier, and create clone of existing using Damage and HP values.
    std::string soldierName = this->generateName();
    SquadMember* newSoldier = new Soldier(this->getHP(), this->getDmg());

    //Set the new Soldier's name and return pointer to new Soldier.
    newSoldier->setName(soldierName);
    return newSoldier;
}

std::string Soldier::generateName()
{
    //Random Generator
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(0, 4);
    int index = dist(engine);

    //Array of Soldier Names
    std::string names[] = {"Elex", "Andry", "Lero", "Zimeon", "Ace"};
    return names[index];
}