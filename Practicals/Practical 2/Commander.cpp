/*
 * Commander.cpp
 *
 *  Created on: 05 Aug 2022
 *      Author: Francois Smith
 */

#include "Commander.h"

/**
 * @brief Base constructor class for commander, generates random name, damage and hp values.
 */
Commander::Commander()
{
    //Set Type
    std::string type = "Commander";
    this->setType(type);

    //Generate random name
    std::string commanderName = this->generateName();
    this->setName(commanderName);

    //Create random number generators
    std::random_device seeder;
    std::mt19937 generator(seeder());
    std::uniform_int_distribution<int> health(6,12);
    std::uniform_int_distribution<int> damage(4,7);

    //Generate random values for hp and dmg
    this->setHP(health(generator));
    this->setDmg(damage(generator));
}

/**
 * @brief Constructor for the Commander class. Defines Damage and HP values. \n
 * @brief Used in clone method to create an exact copy of the Commander except for name field.
 * @param hp - HP of Commander
 * @param dmg - Damage of Commander
 */
Commander::Commander(int hp, int dmg): SquadMember(hp, dmg)
{
    //Set Type
    std::string type = "Commander";
    this->setType(type);
}

/**
 * @brief Constructor for the Commander class. Defines Damage, HP and name values. \n
 * @brief Used when constructing a specific commander with pre set stats and name.
 * @param hp - HP of Commander
 * @param dmg - Damage of Commander
 * @param name - Name of Commander
 */
Commander::Commander(int hp, int dmg, std::string &name) : SquadMember(hp, dmg, name)
{
    //Set Type
    std::string type = "Commander";
    this->setType(type);
}

SquadMember *Commander::clone()
{
    //Generate a random name for the new Commander, and create clone of existing using Damage and HP values.
    std::string commanderName = this->generateName();
    SquadMember* newCommander = new Commander(this->getHP(), this->getDmg());

    //Set the new Commander's name and return pointer to new Commander.
    newCommander->setName(commanderName);
    return newCommander;
}

std::string Commander::generateName()
{
    //Random Generator
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(0, 4);
    int index = dist(engine);

    //Array of Commander Names
    std::string names[] = {"Antorn", "Daryen", "Trephor", "Coltan", "Braydan"};
    return names[index];
}
