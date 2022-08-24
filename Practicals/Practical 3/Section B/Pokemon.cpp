//
// Created by Francois Smith on 2022/08/24.
//

#include "Pokemon.h"

Pokemon::Pokemon(std::string name, int damage, int HP, PlayStyle *playStyle)
{
    this->name = std::move(name);
    this->damage = damage;
    this->playStyle = playStyle;
    this->HP = HP;
    this->battleState = new NormalBattleState();
}

int Pokemon::attack()
{
    if(this->HP > 0)
    {
        std::cout << this->name << this->playStyle->attack() << std::endl;
        std::cout << "    ";
        return this->selectBattleState();
    }
    else
    {
        std::cout << this->name << " has fainted and can not attack." << std::endl;
        return 0;
    }
}

void Pokemon::takeDamage(int damage)
{
    this->HP -= damage;
    if(this->HP <= 0)
    {
        std::cout << this->name << " has fainted." << std::endl;
    }
}

bool Pokemon::isAlive()
{
    return this->HP > 0;
}

void Pokemon::setPlayStyle(PlayStyle* newPlayStyle)
{
    delete this->playStyle;
    this->playStyle = newPlayStyle;
}

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

void Pokemon::print()
{
    std::cout << "Name: " << this->name << " | HP: " << this->HP << " | Damage: " << this->damage << std::endl;
}

Pokemon::~Pokemon()
{
    delete battleState;
    delete playStyle;
}
