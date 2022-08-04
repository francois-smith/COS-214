/*
 * Enemy.cpp
 *
 *  Created on: 02 Aug 2022
 *      Author: Francois Smith
 */

#include "Enemy.h"

Enemy::Enemy(int hp, int dmg, std::string& atk, std::string& name, std::string& def)
{
    this->hp = hp;
    this->dmg = dmg;
    this->atk = atk;
    this->def = def;
    this->name = name;
}

Enemy::~Enemy()
{

}

/**
 * Implements the attack logic for each derived class.
 * Runs specific steps that uses functions defined in lower level classes.
 * @param z - The SquadMember to attack.
 */
void Enemy::attack(SquadMember *z)
{
    while(z->getHP() > 0 and this->getHP() > 0)
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
 * Sets the new Damage value of the enemy.
 * @param newDef - New Damage Value
 */
void Enemy::setDamage(int newDmg)
{
    this->dmg = newDmg;
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
 * Sets the new Attack move of the enemy.
 * @param newAtk - New Attack Property
 */
void Enemy::setAtk(std::string newAtk)

    this->atk = newAtk;
}

/**
 * Returns the defense move of the enemy.
 * @return Defense Move
 */
std::string Enemy::getDef() const
{
    return this->def;
}

/**
 * Sets the new Defence move of the enemy.
 * @param newDef - New Defence Property
 */
void Enemy::setDef(std::string newDef)
{
    this->def = newDef;
}

/**
 * Returns the name of the enemy.
 * @return Name of Enemy
 */
std::string Enemy::getName() const
{
    return this->name;
}

/**
 * Sets the new Name move of the enemy.
 * @param newName - New Name
 */
void Enemy::setName(std::string newName)
{
    this->name = newName;
}

/**
 * Prints the enemy's name, Damage and HP. Used for debugging.
 * @return
 */
std::string Enemy::print()
{
    return "Enemy: " + this->getName()+"\nHP: "+std::to_string(getHP())+"\nDamage: "+std::to_string(getDmg())+"\n";
}
