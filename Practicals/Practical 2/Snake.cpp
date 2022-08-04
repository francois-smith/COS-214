#include "Snake.h"

Snake::Snake(int hp, int dmg, std::string &atk, std::string &def) : Enemy(hp, dmg, atk, def) {}

bool Snake::hitSquadMember(SquadMember* z)
{
    if(z == nullptr) return false;

    std::cout << "Snake wraps around " << z->getName() << " and uses " << this->getAtk() << "." << std::endl;
    if(z->takeDamage(this->getDmg()) <= 0)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Snake::getHit(SquadMember* z)
{
    if(z == nullptr) return false;

    std::cout << "Slithers rapidly searching for safety and employs" << this->getDef() << "." << std::endl;
    int health = this->getHP() - z->getDmg();
    if(health <= 0)
    {
        return true;
    }
    else {
        this->setHP(health);
        return false;
    }
}

void Snake::celebrate()
{
    std::cout << "Player tried strongly till the end." << std::endl;
}

void Snake::die()
{
    std::cout << "Snake hisses and curls up as he is defeated." << std::endl;
}
