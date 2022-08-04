#pragma once
#include <string>

class SquadMember {
public:
    SquadMember(int hp, std::string& name, int dmg);
    int getDmg() const;
    void setDmg(int newDmg);
    int getHP() const;
    void setHP(int newHp);
    std::string getName() const;
    int takeDamage(int damage);
    void die();
    SquadMember* clone();

protected:
    std::string name;
    int dmg;
    int hp;
};
