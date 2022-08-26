//
// Created by Francois Smith on 2022/08/24.
//

#include "Pokemon.h"

/**
 * @brief Constructor for Pokemon class
 * @param name - Name of Pokemon
 * @param damage - Damage of Pokemon
 * @param HP - HP of Pokemon
 * @param playStyle - PlayStyle of Pokemon
 */
Pokemon::Pokemon(std::string name, int damage, int HP, PlayStyle *playStyle)
{
    this->name = std::move(name);
    this->damage = damage;
    this->playStyle = playStyle;
    this->HP = HP;
    this->battleState = new NormalBattleState();
}

/**
 * Attack function for Pokemon class, checks if Pokemon is alive and swaps state after attack
 * @return - Damage dealt by Pokemon
 */
int Pokemon::attack()
{
    //Check if Pokemon is alive
    if(this->HP > 0)
    {
        //Output attack message
        std::cout << this->name << this->playStyle->attack() << std::endl;
        std::cout << "    ";
        //Swap state
        return this->selectBattleState();
    }
    else
    {
        //Output that Pokemon cannot fight
        std::cout << this->name << " has fainted and can not attack." << std::endl;
        return 0;
    }
}

/**
 * @brief Receive damage from another Pokemon
 * @param damage - Damage to take
 */
void Pokemon::takeDamage(int damage)
{
    this->HP -= damage;
    if(this->HP <= 0)
    {
        std::cout << this->name << " has fainted." << std::endl;
    }
}

/**
 * @brief Checks if Pokemon is alive
 * @return - True if Pokemon is alive, false otherwise
 */
bool Pokemon::isAlive()
{
    return this->HP > 0;
}

/**
 * @brief Sets new PlayStyle for Pokemon
 * @param newPlayStyle - New PlayStyle for Pokemon
 */
void Pokemon::setPlayStyle(PlayStyle* newPlayStyle)
{
    delete this->playStyle;
    this->playStyle = newPlayStyle;
}

/**
 * @brief Randomly selects new BattleState for Pokemon
 * @return - Damage dealt by Pokemon with new BattleState
 */
int Pokemon::selectBattleState()
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed1);
    std::uniform_int_distribution<int> dist(1, 3);

    int randomNumber = dist(generator);
    delete battleState;

    switch(randomNumber)
    {
        default:  case 1:{
            battleState = new NormalBattleState();
            break;
        }
        case 2:{
            battleState = new AgileBattleState();
            break;
        }
        case 3:{
            battleState = new StrongBattleState();
            break;
        }
    }
    return battleState->handle(this->name, this->damage);
}

/**
 * @brief Prints Pokemon's information
 */
void Pokemon::print()
{
    std::cout << "Name: " << this->name << " | HP: " << this->HP << " | Damage: " << this->damage << std::endl;
}

/**
 * @brief Destructor for Pokemon class, deallocates memory
 */
Pokemon::~Pokemon()
{
    delete battleState;
    delete playStyle;
}
