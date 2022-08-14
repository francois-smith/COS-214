/*
 * main.cpp
 *
 *  Created on: 07 Aug 2022
 *      Author: Francois Smith
 */

//Default Includes
#include <vector>
#include <array>
#include <cassert>

//Includes for SquadMembers
#include "SquadMember.h"
#include "Commander.h"
#include "Mercenary.h"
#include "Soldier.h"

//Includes for EnemyFactories
#include "JaguarFactory.h"
#include "GorillaFactory.h"
#include "CannibalFactory.h"
#include "SnakeFactory.h"

//Includes for Enemies
#include "Enemy.h"
#include "Jaguar.h"
#include "Gorilla.h"
#include "Cannibal.h"
#include "Snake.h"

//Includes for Saving and Loading
#include "GameStore.h"

/**
 * @brief Generates a random number between min and max.
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

/**
 * @brief Generates a random SquadMember.
 * @return Pointer to newly created SquadMember
 */
SquadMember* generateSquadMember()
{
    //Generate Random Number
    int type = generateRandomNumber(0, 2);

    //Construct new SquadMember Randomly
    SquadMember* newMember;
    switch(type)
    {
        default: case 0: newMember = new Commander(); break;
        case 1: newMember = new Mercenary(); break;
        case 2: newMember = new Soldier(); break;
    }

    return newMember;
}

/**
 * @brief Clones passed in SquadMember.
 * @param member - SquadMember to be cloned
 * @return Pointer to newly created SquadMember
 */
SquadMember* cloneMember(SquadMember* member)
{
    //Generate Random Number
    SquadMember* newMember = member->clone();
    std::cout << newMember->getName() << " has been added to the squad!\n";
    return newMember;
}

/**
 * @brief Function that generates a random enemy for the squad to fight.
 * @param factories - Vector of EnemyFactories to choose from.
 * @return Pointer to the Enemy that was generated.
 */
Enemy* generateRandomEnemy(std::array<EnemyFactory*, 4> factories)
{
    //Create Random Enemy
    int type = generateRandomNumber(0, 3);
    switch (type)
    {
        //Snake
        default: case 0:{
            //Output Message and Abilities
            std::cout << "A snake slithers rapidly in your direction!\n";
            std::string attacks[] = {"Venomous Strike", "Spit", "Wraps"};
            std::string defences[] = {"Coil", "Dash", "Pounce"};

            //Create new Snake
            Enemy* enemy = factories[type]->createEnemy(attacks[generateRandomNumber(0, 2)], defences[generateRandomNumber(0, 2)]);
            enemy->print();
            return enemy;
        }
        //Jaguar
        case 1:{
            //Output Message and Abilities
            std::cout << "A ferocious jaguar appears!\n";
            std::string attacks[] = {"Big Claws", "Pounce", "Roar"};
            std::string defences[] = {"Side Step", "Tail Whip", "Back Step"};

            //Create new Jaguar
            Enemy* enemy = factories[type]->createEnemy(attacks[generateRandomNumber(0, 2)], defences[generateRandomNumber(0, 2)]);
            enemy->print();
            return enemy;
        }
        //Gorilla
        case 2:{
            //Output Message and Abilities
            std::cout << "The ground trembles as a gorilla appears!\n";
            std::string attacks[] = {"Pound", "Rock Throw", "Feral Hit"};
            std::string defences[] = {"Chest Pound", "Spin", "Back Step"};

            //Create new Gorilla
            Enemy* enemy = factories[type]->createEnemy(attacks[generateRandomNumber(0, 2)], defences[generateRandomNumber(0, 2)]);
            enemy->print();
            return enemy;
        }
        //Cannibal
        case 3:{
            //Output Message and Abilities
            std::cout << "A cannibal jumps out from behind a bush!\n";
            std::string attacks[] = {"Sling Shot", "Bone Spear", "Wooden Bow"};
            std::string defences[] = {"Roll", "Yell", "Kick"};

            //Create new Cannibal
            Enemy* enemy = factories[type]->createEnemy(attacks[generateRandomNumber(0, 2)], defences[generateRandomNumber(0, 2)]);
            enemy->print();
            return enemy;
        }
    }
}

/**
 * @brief Function that lets the squad fight an enemy. If a squad member is killed, it is removed from the list and the next squad member is selected.
 * @param enemy - Enemy to fight.
 * @param squad - Squad Reference.
 * @return If the squad won.
 */
bool fight(Enemy* enemy, std::vector<SquadMember*>* squad)
{
    //Loop until no squad members are left
    for(SquadMember* member: *squad)
    {
        //Call template function
        enemy->attack(member);

        //determines if the squad member is dead
        if (member->getHP() <= 0)
        {
            //remove squad member from list
            delete member;
            squad->erase(squad->begin());
        }
        //determines if the enemy is dead
        else if (enemy->getHP() <= 0)
        {
            //Fight is won
            return true;
        }
    }

    //If reaching this point the squad lost
    return false;
}

/**
 * @brief Clears all memory allocated throughout the game if user does not want to redo.
 * @param enemy - Enemy Reference
 * @param squad - Squad Reference
 * @param factories - Factories Reference
 */
bool endGame(std::vector<SquadMember*>* squad, std::array<EnemyFactory*, 4>* factories)
{
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
    return true;
}

/**
 * @brief Outputs the current state of the squad. \n
 * @brief Prints all members displaying their name, type, health and damage.
 * @param squad - Squad Reference
 */
void squadStatus(std::vector<SquadMember*>* squad)
{
    std::cout << "Current squad consists of:" << std::endl;
    for(SquadMember* member: *squad) {
        std::cout << "-----------------------------------------------------------" << std::endl;
        std::cout << "=      " << member->getName() << ": | Type - " << member->getType() << " | HP - " << member->getHP() << " | DMG - " << member->getDmg() << std::endl;
    }
    std::cout << "-----------------------------------------------------------" << std::endl;
}

/**
 * @brief Saves the current state of the game.
*/
void saveGame(std::vector<SquadMember*>* squad, Enemy* enemy, GameStore* store)
{
    std::cout << "Saving game...\n";
    store->setEnemy(enemy);
    store->setSquadMembers(*squad);
    store->save();
}

/**
 * @brief Loads the last saved game.
*/
void loadGame(std::vector<SquadMember*>* squad, Enemy* enemy, GameStore* store)
{
    std::cout << "Loading game...\n";
    store->load();
    enemy = store->getEnemy();

    //Clear Existing Squad
    std::vector<SquadMember*> squadSave = store->getSquadMembers();
    for(SquadMember* member : *squad)
    {
        delete member;
    }
    squad->clear();

    //Copy Saved Squad
    for(SquadMember* member : squadSave)
    {
        SquadMember* clonedMember = member->clone();
        std::string name = member->getName();
        clonedMember->setName(name);
        squad->push_back(clonedMember);
    }
}

/**
 * @brief Asks for the user input to either run a simulation or pre defined main for testing functionality.
 * @return - Run Simulation or Pre Defined Main.
 */
bool startGame()
{
    while(true)
    {
        std::string userChoice;
        std::cout << "========== How do You Want to Play =========" << std::endl;
        std::cout << "[1] Play Simulation" << std::endl;
        std::cout << "[2] Test Code" << std::endl;
        std::cin >> userChoice;
        std::cout << std::endl;
        if(userChoice == "1")
        {
            return true;
        }
        else if(userChoice == "2")
        {
            return false;
        }
    }
}

/**
 * @brief Asks user for difficulty they want to play on.
 * @return - Selected Difficulty.
 */
int getDifficulty()
{
    while(true)
    {
        std::string userChoice;
        std::cout << "============== Select Difficulty =============" << std::endl;
        std::cout << "[1] Beginner" << std::endl;
        std::cout << "[2] Intermediate" << std::endl;
        std::cout << "[3] Challenge" << std::endl;
        std::cout << "[4] Death" << std::endl;
        std::cin >> userChoice;
        std::cout << std::endl;
        if(userChoice == "1" || userChoice == "2" || userChoice == "3" || userChoice == "4")
        {
            return std::stoi(userChoice);
        }
    }
}

/**
 * @brief Used to simulate spec tests. \n
 * @brief Verifies that all design patters are implemented and runs various tests to verify functionality.
 */
void debugGame()
{
    std::cout << "=========================== Testing Task 1 ===========================\n";
    //Creating enemies array
    Enemy** enemies = new Enemy*[4];
    std::string attack = "attack";
    std::string defense = "defense";
    std::string name = "name";

    //Generate one of each enemy type
    enemies[0] = new Snake(1, 1, attack, name, defense);
    enemies[1] = new Jaguar(1, 1, attack, name, defense);
    enemies[2] = new Gorilla(1, 1, attack, name, defense);
    enemies[3] = new Cannibal(1, 1, attack, name, defense);

    //Create a predefined squad member
    std::string squadMemberName = "John";
    SquadMember* member = new Commander(50, 20, squadMemberName);

    //Loop through all enemies and run main functions to verify that the work
    std::string enemiesTypes[] = {"Snake", "Jaguar", "Gorilla", "Cannibal"};
    for (int i = 0; i < 4; i++)
    {
        std::cout << enemiesTypes[i] << ": " << std::endl;
        enemies[i]->print();
        enemies[i]->hitSquadMember(member);
        enemies[i]->getHit(member);
        enemies[i]->celebrate();
        enemies[i]->die();
        std::cout <<std:: endl;
    }

    //Free up memory
    for (int i = 0; i < 4; i++)
        delete enemies[i];
    delete[] enemies;
    delete member;
    std::cout << std::endl;

    std::cout << "=========================== Testing Task 2 ===========================\n";
    //Creating enemies
    enemies = new Enemy*[4];

    //Creating Commander
    squadMemberName = "John";
    member = new Commander(200, 20, squadMemberName);

    //Creating factories
    EnemyFactory **enemyFactories = new EnemyFactory *[4];
    enemyFactories[0] = new SnakeFactory();
    enemyFactories[1] = new JaguarFactory();
    enemyFactories[2] = new GorillaFactory();
    enemyFactories[3] = new CannibalFactory();
    std::cout << std::endl;

    //Testing factories
    for (int i = 0; i < 4; i++)
    {
        enemies[i] = enemyFactories[i]->createEnemy("attack", "defense");
        std::cout << "Generating Random " << enemies[i]->getName() << " With Factory: " << std::endl;
        enemies[i]->print();
        enemies[i]->hitSquadMember(member);
        enemies[i]->getHit(member);
        enemies[i]->celebrate();
        enemies[i]->die();
        std::cout << std::endl;
    }

    //Clear Allocated Memory
    for (int i = 0; i < 4; i++)
    {
        delete enemies[i];
        delete enemyFactories[i];
    }
    delete[] enemies;
    delete[] enemyFactories;
    delete member;
    std::cout << std::endl;

    std::cout << "=========================== Testing Task 3 ===========================\n";

    //Creating squadMember
    std::cout << "Generating Commander John... " << std::endl;
    squadMemberName = "John";
    member = new Commander(200, 20, squadMemberName);

    //Create clone of John
    std::cout << "Cloning John..." << std::endl << std::endl;
    SquadMember* squadMemberClone = member->clone();
    assert(member != squadMemberClone);

    //Outputting members to verify that they are the same
    std::cout << "SquadMember 1: " << member->getName() << std::endl;
    member->printStats();
    std::cout<< "Cloned SquadMember: " << squadMemberClone->getName() << std::endl;
    squadMemberClone->printStats();

    //Testing Whether squadMemberClone is a clone of member
    std::cout << "Running Assertions on Type, HP and DMG" << std::endl;
    assert(member->getType() == squadMemberClone->getType());
    assert(member->getHP() == squadMemberClone->getHP());
    assert(member->getDmg() == squadMemberClone->getDmg());
    std::cout << "Assertions Passed" << std::endl << std::endl;

    //Change stats of squadMemberClone
    std::cout << "Updating John to Benny..." << std::endl;
    std::cout << "Updating Stats..." << std::endl << std::endl;
    member->setHP(100);
    std::string newName = "Benny";
    member->setName(newName);
    member->setDmg(22);

    //Outputting members to show that they are different
    std::cout << "SquadMember 1: " << member->getName() << std::endl;
    member->printStats();
    std::cout<< "Cloned SquadMember: " << squadMemberClone->getName() << std::endl;
    squadMemberClone->printStats();

    //Testing SquadMembers to verify that they are different
    std::cout << "Running Assertions on changed HP and DMG" << std::endl;
    assert(member->getHP() != squadMemberClone->getHP());
    assert(member->getDmg() != squadMemberClone->getDmg());
    std::cout << "Assertions Passed" << std::endl << std::endl;

    //Free Allocated Memory
    delete squadMemberClone;
    delete member;
    std::cout << std::endl;

    std::cout << "=========================== Run Simulation To Test 4.1 - Adventure of a Life Time ===========================\n\n";
    std::cout << "=========================== Testing Task 4.2 ===========================\n";

    //Create Squad
    std::cout << "Generating Squad Vector..." << std::endl;
    std::vector<SquadMember*>* squadMembers = new std::vector<SquadMember*> {new Commander(), new Soldier()};

    //Create Enemy
    std::cout << "Generating Enemy To Fight..." << std::endl;
    SnakeFactory snakeFactory;
    Enemy* enemy = snakeFactory.createEnemy("attack", "defense");

    //Create GameStore to test memento pattern
    GameStore* gameStore = new GameStore(enemy, *squadMembers);

    //Output Enemy and Squad to verify state before saving
    squadStatus(squadMembers);
    std::cout << "Current Enemy: " << std::endl;
    enemy->print();

    //Save Game
    saveGame(squadMembers, enemy, gameStore);

    //Change all stats of squadMembers and enemy
    std::cout << "Updating Squad Details...\n";
    squadMembers->at(0)->setHP(45);
    squadMembers->at(0)->setDmg(66);
    squadMembers->at(1)->setHP(50);
    squadMembers->at(1)->setDmg(22);
    enemy->setHP(20);
    enemy->setDamage(10);

    //Show new stats of squadMembers and enemy
    std::cout << "Current Squad Stats After Update: " << std::endl;
    squadStatus(squadMembers);
    std::cout << "Updated Enemy: " << std::endl;
    enemy->print();

    //Load Game
    std::cout << "Restoring Initial Squad From Save: \n";
    loadGame(squadMembers, enemy, gameStore);

    //Verify that squadMembers and enemy are the same as before after load
    std::cout << "Squad Stats After Restore: " << std::endl;
    squadStatus(squadMembers);
    std::cout << "Enemy After Load: " << std::endl;
    enemy->print();

    //Clear Allocated Memory
    for(SquadMember* squadMember: *squadMembers)
    {
        delete squadMember;
    }
    squadMembers->clear();
    delete squadMembers;
    delete enemy;
    delete gameStore;
}

int userPrompt()
{
    while(true)
    {
        std::string userChoice;
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "[1] Fight!" << std::endl;
        std::cout << "[2] Squad Status" << std::endl;
        std::cout << "[3] Save Game" << std::endl;
        std::cout << "[4] Load Game" << std::endl;
        std::cout << "[5] Exit Game" << std::endl;
        std::cin >> userChoice;
        std::cout << std::endl;
        if(userChoice == "1" || userChoice == "2" || userChoice == "3" || userChoice == "4")
        {
            return stoi(userChoice);
        }
    }
}

int main() {
    //Run simulation(Random Scenarios)
    //First few steps of simulation are predefined, once third squad member is generated, the rest of the steps are random
    if(startGame())
    {
        //SquadMembers and Enemy Variables
        std::vector<SquadMember*>* squad = new std::vector<SquadMember*>();
        Enemy* enemy = nullptr;
        int currentEnemy = 0;
        GameStore* gameStore = new GameStore(enemy, *squad);
        std::array<EnemyFactory*, 4> factories = {new SnakeFactory(), new JaguarFactory(), new GorillaFactory(), new CannibalFactory()};

        //Starting Message
        std::cout << "Adventure of a Life Time! \n" << std::endl;
        std::cout << "Generating Squad..." << std::endl;

        for (int i = 0; i < 4; ++i)
        {
            squad->push_back(generateSquadMember());
        }
        squadStatus(squad);

        int difficulty = getDifficulty() -1;
        int numEnemies = 0;
        switch (difficulty) {
            default: case 0: numEnemies = 2; break;
            case 1: numEnemies = 3; break;
            case 2: numEnemies = 5; break;
            case 3: numEnemies = 7; break;
        }

        for (int i = 0; i < numEnemies; ++i)
        {
            enemy = generateRandomEnemy(factories);
            input:
            std::cout << i << "/" << numEnemies << " Defeated" << std::endl;
            int input = userPrompt();
            if(input == 1)
            {
                if(fight(enemy, squad)) {
                    std::cout << "The squad has won the battle!\n\n";
                }
                else {
                    std::cout << "The squad has lost the battle!\n";
                    endGame(squad, &factories);
                    std::cout << "Game Over\n";
                    delete enemy;
                    return 0;
                }
            }
            else if(input == 2)
            {
                squadStatus(squad);
                goto input;
            }
            else if(input == 3)
            {
                saveGame(squad, enemy, gameStore);
                currentEnemy = i;
                goto input;
            }
            else if(input == 4)
            {
                loadGame(squad, enemy, gameStore);
                i = currentEnemy;
                goto input;
            }
            else if(input == 5)
            {
                std::cout << "Thank you for playing!" << std::endl;
                endGame(squad, &factories);
                delete enemy;
                return 0;
            }
        }

        std::cout << "All enemies have been defeated! Game over, good job soldier." << std::endl;
        std::cout << "Thank you for playing!" << std::endl;
        endGame(squad, &factories);
        delete enemy;
    }
    //Run Test Cases
    else
    {
        //Debug Function
        debugGame();
        return 0;
    }
}
