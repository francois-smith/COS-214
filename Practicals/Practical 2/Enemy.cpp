/*
 * Enemy.cpp
 *
 *  Created on: 02 Aug 2022
 *      Author: Francois Smith
 */

#include "Enemy.h"

/**
 * @brief Default constructor for the Enemy class.
 * @param hp - Enemy's HP
 * @param dmg - Enemy's Damage
 * @param atk  - Enemy's Attack Move
 * @param name - Enemy's Name
 * @param def - Enemy's Defense Move
 */
Enemy::Enemy(int hp, int dmg, std::string& atk, std::string& name, std::string& def)
{
    this->hp = hp;
    this->dmg = dmg;
    this->atk = atk;
    this->name = name;
    this->def = def;
    this->state = nullptr;
}

/**
 * @brief Implements the attack logic for each derived class.
 * @brief Runs specific functions that are defined in lower level classes.
 * @param z - The SquadMember to attack.
 */
void Enemy::attack(SquadMember *z)
{
    //Checks that the enemy and squad member are not dead.
    while(z->getHP() > 0 and this->getHP() > 0)
    {
        //If squad member dies from attack
        if(hitSquadMember(z))
        {
            //Prints that the squad member is dead. And let enemy celebrate.
            z->die();
            celebrate();
            return;
        }
        //Else if squad member survives attack
        else
        {
            //Squad member counter-attacks
            std::cout << z->getName() << " survived and counterattacks, dealing " << z->getDmg() << " damage." << std::endl;

            //If attack kills the enemy
            if(getHit(z))
            {
                die();
                return;
            }
        }
    }
}

/**
 * @brief Sets the new HP value of the enemy.
 * @param newHp - New Value
 */
void Enemy::setHP(int newHp)
{
    this->hp = newHp;
}

/**
 * @brief Returns the current HP value of the enemy.
 * @return Current HP value.
*/
int Enemy::getHP() const
{
    return this->hp;
}

/**
 * @brief Returns the damage value of the enemy.
 * @return Damage value.
*/
int Enemy::getDmg() const
{
    return this->dmg;
}

/**
 * @brief Sets the new Damage value of the enemy.
 * @param newDmg - New Damage Value
 */
void Enemy::setDamage(int newDmg)
{
    this->dmg = newDmg;
}

/**
 * @brief Returns the attack move of the enemy.
 * @return  Attack Move
 */
std::string Enemy::getAtk() const
{
    return this->atk;
}

/**
 * @brief Sets the new Attack move of the enemy.
 * @param newAtk - New Attack Property
 */
void Enemy::setAtk(std::string& newAtk)
{
    this->atk = newAtk;
}

/**
 * @brief Returns the defense move of the enemy.
 * @return Defense Move
 */
std::string Enemy::getDef() const
{
    return this->def;
}

/**
 * @brief Sets the new Defence move of the enemy.
 * @param newDef - New Defence Property
 */
void Enemy::setDef(std::string& newDef)
{
    this->def = newDef;
}

/**
 * @brief Returns the name of the enemy.
 * @return Name of Enemy
 */
std::string Enemy::getName() const
{
    return this->name;
}

/**
 * @brief Sets the new Name move of the enemy.
 * @param newName - New Name
 */
void Enemy::setName(std::string& newName)
{
    this->name = newName;
}

/**
 * @brief Prints the enemy's Damage and HP.
 */
void Enemy::print() const
{
    std::cout << "------------------------------------" << std::endl;
    std::cout << "=      " << "HP: " << this->getHP() << " | DMG: " << this->getDmg() << std::endl;
    std::cout << "------------------------------------" << std::endl << std::endl;;
}

/*
 * @brief Loads save from state.
 */
void Enemy::loadSave(EnemyState* const save)
{
    state = save;
    this->setDamage(this->state->getDmg());
    this->setHP(this->state->getHp());

    std::string saveName = this->state->getName();
    this->setName(saveName);

    std::string saveAtk = this->state->getName();
    this->setAtk(saveAtk);

    std::string saveDef = this->state->getName();
    this->setDef(saveDef);
}

/**
 * @brief Saves current state of enemy.
 * @return State of Enemy.
 */
EnemyState* Enemy::saveGame()
{
    return new EnemyState(hp, dmg, atk, def, name);
}
