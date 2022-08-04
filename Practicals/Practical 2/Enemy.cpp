#include "Enemy.h"

Enemy::Enemy(int hp, int dmg, std::string& atk, std::string& def)
{
    this->hp = hp;
    this->dmg = dmg;
    this->atk = atk;
    this->def = def;
}

/**
 * Implements the attack logic for each derived class.
 * Runs specific steps that uses functions defined in lower level classes.
 * @param z - The SquadMember to attack.
 */
void Enemy::attack(SquadMember *z)
{
    if(z->getHP() > 0)
    {
       if(hitSquadMember(z))
       {
           z->die();
           this->celebrate();
       }
       else
       {
           if(getHit(z))
           {
               this->die();
           }
       }
    }
}

/**
 * Sets the new HP value of the enemy.
 * @param hp - New Value
 */
void Enemy::setHP(int hp)
{
    this->hp = hp;
}

/**
 * Returns the current HP value of the enemy.
 * @return Current HP value.
*/
int Enemy::getHP() const
{
    return this->hp;
}

/**
 * Returns the damage value of the enemy.
 * @return Damage value.
*/
int Enemy::getDmg() const
{
    return this->dmg;
}

/**
 * Returns the attack move of the enemy.
 * @return  Attack Move
 */
std::string Enemy::getAtk() const
{
    return this->atk;
}

/**
 * Returns the defense move of the enemy.
 * @return Defense Move
 */
std::string Enemy::getDef() const
{
    return this->def;
}
