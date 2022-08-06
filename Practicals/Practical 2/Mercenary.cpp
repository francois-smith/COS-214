/*
 * Mercenary.cpp
 *
 *  Created on: 05 Aug 2022
 *      Author: Francois Smith
 */

#include "Mercenary.h"

/**
 * @brief Base constructor class for Mercenary, generates random name, damage and hp values.
 */
Mercenary::Mercenary()
{
    //Set Type
    std::string type = "Mercenary";
    this->setType(type);

    //Generate random name
    std::string mercenaryName = this->generateName();
    this->setName(mercenaryName);

    //Create random number generators
    std::random_device device;
    std::default_random_engine generator{device()};
    std::uniform_int_distribution<int> health(3,7);
    std::uniform_int_distribution<int> damage(3,9);

    //Generate random values for hp and dmg
    this->setHP(health(generator));
    this->setDmg(damage(generator));
}

/**
 * @brief Constructor for the Mercenary class. Defines Damage and HP values. \n
 * @brief Used in clone method to create an exact copy of the Mercenary except for name field.
 * @param hp - HP of Mercenary
 * @param dmg - Damage of Mercenary
 */
Mercenary::Mercenary(int hp, int dmg): SquadMember(hp, dmg)
{
    //Set Type
    std::string type = "Mercenary";
    this->setType(type);
}

/**
 * @brief Constructor for the Mercenary class. Defines Damage, HP and name values. \n
 * @brief Used when constructing a specific mercenary with pre set stats and name.
 * @param hp - HP of Mercenary
 * @param dmg - Damage of Mercenary
 * @param name - Name of Mercenary
 */
Mercenary::Mercenary(int hp, int dmg, std::string &name) : SquadMember(hp, dmg, name)
{
    //Set Type
    std::string type = "Mercenary";
    this->setType(type);
}

SquadMember *Mercenary::clone()
{
    //Generate a random name for the new Mercenary, and create clone of existing using Damage and HP values.
    std::string mercenaryName = this->generateName();
    SquadMember* newMercenary = new Mercenary(this->getHP(), this->getDmg());

    //Set the new Mercenary's name and return pointer to new Mercenary.
    newMercenary->setName(mercenaryName);
    return newMercenary;
}

std::string Mercenary::generateName()
{
    //Random Generator
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(0, 4);
    int index = dist(engine);

    //Array of Commander Names
    std::string names[] = {"Jaime", "Derral", "Ned", "Ralof", "Lyonel"};
    return names[index];
}
