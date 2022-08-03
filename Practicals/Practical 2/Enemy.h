#pragma once

class SquadMember;

class Enemy {
public:
    Enemy();
    ~Enemy();
    void attack();
    bool hitSquadMember(SquadMember* z);
    void celebrate();
    bool getHit(SquadMember* z);
    void die();

private:


protected:


public:


private:


protected:
    int HP;

};
