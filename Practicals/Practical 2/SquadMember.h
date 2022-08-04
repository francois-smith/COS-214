#pragma once
#include <string>

class SquadMember
{
public:
    SquadMember(int hp, std::string& name, int dmg);
    int getDmg() const;
    void setDmg(int newDmg);
    int getHP() const;
    void setHP(int newHp);
    int getDamage() const;
    void setDamage(int newDmg);
    std::string getName() const;
    int takeDamage(int damage);
    void die();
    virtual SquadMember* clone() = 0;

    /**
     * Generates a random name for an SquadMember.
     * @return Generated Name
     */
    virtual std::string generateName() = 0;

protected:
    std::string name;
    int dmg;
    int hp;
};
