#pragma once
#include <string>
#include "monster.h"
class monster;
class player {
protected:
    std::string name;
    int job;
    int level;
    int maxhp;
    int maxmp;
    int hp;
    int mp;
    int power;
    int defence;
    int exp;
    int maxexp;
    int Damage;
    monster* Monster;
public:
    player(std::string name, int stat[], int job);
    virtual void printPlayerStatus() = 0;
    virtual void attack(monster* Monster) = 0;

    void takeDamage(int damage);

    int getHP() const;
    int getMP() const;
    int getPower() const;
    int getDefence() const;
    int getJob() const;
    int getExp() const;
    int getMaxExp() const;
    int getLevel() const;
    int getDamage() const;
    int getMaxHP() const;
    int getMaxMP() const;

    
    void setMaxHP(int maxhp);
    void setMaxMP(int maxmp);
    void setDamage(int newDamage);
    void setExp(int exp);
    void setMaxExp(int maxexp);
    void setLevel(int level);
    void setHP(int hp);
    void setMP(int mp);
    void setPower(int att);
    void setDefence(int def);

    virtual ~player();
};