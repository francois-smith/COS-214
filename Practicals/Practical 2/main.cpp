/*
 * main.cpp
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

//Default Includes
#include <vector>
#include <array>

//Includes for SquadMembers
#include "SquadMember.h"
#include "Commander.h"
#include "Mercenary.h"
#include "Soldier.h"

//Includes for EnemyFactories and Enemy Base Class
#include "Enemy.h"
#include "JaguarFactory.h"
#include "GorillaFactory.h"
#include "CannibalFactory.h"
#include "SnakeFactory.h"

//Includes for Memento and Enemy Base Class
#include "EnemyStore.h"

/**
 * Generates a random number between min and max.
 * @param min - Min Value
 * @param max - Max Value
 * @return Random Number
 */
int generateRandomNumber(int min, int max)
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed1);
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}

SquadMember* generateSquadMember()
{
    //Generate Random Number
    std::cout << "Generating random squad member...\n";
    int type = generateRandomNumber(0, 2);

    //Construct new SquadMember Randomly
    SquadMember* newMember = nullptr;
    switch (type)
    {
        default: case 0: newMember = new Commander(); break;
        case 1: newMember = new Mercenary(); break;
        case 2: newMember = new Soldier(); break;
    }

    std::cout << newMember->getName() << " has been added to the squad!\n";
    newMember->printStats();
    return newMember;
}

SquadMember* cloneMember(SquadMember* member)
{
    //Generate Random Number
    SquadMember* newMember = member->clone();
    std::cout << newMember->getName() << " has been added to the squad!\n";
    return newMember;
}

/**
 * Function that generates a random enemy for the squad to fight.
 * @param factories - Vector of EnemyFactories to choose from.
 * @return Pointer to the Enemy that was generated.
 */
Enemy* generateRandomEnemy(std::array<EnemyFactory*, 4> factories)
{
    //Create Random Enemy
    int type = generateRandomNumber(0, 3);
    switch (type)
    {
        default: case 0:{
            //Output Message and Abilities
            std::cout << "A snake slithers rapidly in your direction!\n";
            std::string attacks[] = {"Venomous Strike", "Spit", "Wraps"};
            std::string defences[] = {"Coil", "Dash", "Pounce"};

            //Create new Snake
            Enemy* enemy = factories[type]->createEnemy(attacks[generateRandomNumber(1, 3)], defences[generateRandomNumber(1, 3)]);
            enemy->print();
            return enemy;
        }
        case 1:{
            //Output Message and Abilities
            std::cout << "A ferocious jaguar appears!\n";
            std::string attacks[] = {"Big Claws", "Pounce", "Roar"};
            std::string defences[] = {"Side Step", "Tail Whip", "Back Step"};

            //Create new Jaguar
            Enemy* enemy = factories[type]->createEnemy(attacks[generateRandomNumber(1, 3)], defences[generateRandomNumber(1, 3)]);
            enemy->print();
            return enemy;
        }
        case 2:{
            //Output Message and Abilities
            std::cout << "The ground trembles as a gorilla appears!\n";
            std::string attacks[] = {"Pound", "Rock Throw", "Feral Hit"};
            std::string defences[] = {"Chest Pound", "Spin", "Back Step"};

            //Create new Gorilla
            Enemy* enemy = factories[type]->createEnemy(attacks[generateRandomNumber(1, 3)], defences[generateRandomNumber(1, 3)]);
            enemy->print();
            return enemy;
        }
        case 3:{
            //Output Message and Abilities
            std::cout << "A cannibal jumps out from behind a bush!\n";
            std::string attacks[] = {"Sling Shot", "Bone Spear", "Wooden Bow"};
            std::string defences[] = {"Roll", "Yell", "Kick"};

            //Create new Cannibal
            Enemy* enemy = factories[type]->createEnemy(attacks[generateRandomNumber(1, 3)], defences[generateRandomNumber(1, 3)]);
            enemy->print();
            return enemy;
        }
    }
}

/**
 * Function that lets the squad fight an enemy. If a squad member is killed, it is removed from the squad and the next squad member is selected.
 * @param enemy - Enemy to fight.
 * @param squad - Squad members
 * @return If the squad is won.
 */
bool fight(Enemy* enemy, std::vector<SquadMember*>* squad)
{
    for(SquadMember* member: *squad)
    {
        enemy->attack(member);
        if (member->getHP() <= 0)
        {
            delete member;
            squad->erase(squad->begin());
        }
        else if (enemy->getHP() <= 0)
        {
            delete enemy;
            return true;
        }
    };

    delete enemy;
    return false;
}

/**
 * Clears all memory allocated throughout the game.
 * @param enemy - Enemy Reference
 * @param squad - Squad Reference
 * @param factories - Factories Reference
 */
void endGame(std::vector<SquadMember*>* squad, std::array<EnemyFactory*, 4>* factories)
{
    //Delete all squad members
    for(SquadMember* member: *squad)
    {
        delete member;
    }
    squad->clear();

    //Delete all factories
    for(EnemyFactory* factory: *factories)
    {
        delete factory;
    }
}

void squadStatus(std::vector<SquadMember*>* squad)
{
    std::cout << "Current squad consists of:" << std::endl;
    for(SquadMember* member: *squad) {
        std::cout << "-----------------------------------------------------------" << std::endl;
        std::cout << "=      " << member->getName() << ": | Type - " << member->getType() << " | HP - " << member->getHP() << " | DMG - " << member->getDmg() << std::endl;
    };
    std::cout << "-----------------------------------------------------------" << std::endl;
}

void saveGame(EnemyStore& enemyStore)
{
    std::cout << "Saving game...\n";
    if(enemyStore.getEnemy() != nullptr)
    {
        std::cout << "Saving enemy's state...\n";
        enemyStore.save();
    }
    else
    {
        std::cout << "No enemy to save!\n";
    }

}

int main() {
    //SquadMembers and Stores
    std::vector<SquadMember*> squad;


    std::array<EnemyFactory*, 4> factories = {new SnakeFactory(), new JaguarFactory(), new GorillaFactory(), new CannibalFactory()};
    EnemyStore enemyStore(nullptr);
    Enemy* enemy = nullptr;
    std::cout << "Adventure of a Life Time! \n" << std::endl;

    squad.push_back(generateSquadMember());
    std::cout << "Squad moves further into the island...\n";
    enemy = generateRandomEnemy(factories);
    enemyStore.setEnemy(enemy);
    if(fight(enemy, &squad)) {
        std::cout << "The squad has won the battle!\n\n";
        enemyStore.clear();
        squadStatus(&squad);
    }
    else {
        std::cout << "The squad has lost the battle!\nGame Over...";
        endGame(&squad, &factories);
        return 0;
    }

    std::cout << "Squad moves further into the island...\nSquad find a village and recruits a new member.\n";
    squad.push_back(generateSquadMember());

    enemy = generateRandomEnemy(factories);
    enemyStore.setEnemy(enemy);
    if(fight(enemy, &squad)) {
        std::cout << "The squad has won the battle!\n\n";
        enemyStore.clear();
    }
    else {
        std::cout << "The squad has lost the battle!\nGame Over...";
        endGame(&squad, &factories);
        return 0;
    }

    std::cout << "While exploring the village, the squad saves " << squad.back()->getName() << "'s brother.\n";
    squad.push_back(cloneMember(squad.back()));
    squadStatus(&squad);

    enemy = generateRandomEnemy(factories);
    enemyStore.setEnemy(enemy);
    saveGame(enemyStore);



    endGame(&squad, &factories);
    return 0;
}
