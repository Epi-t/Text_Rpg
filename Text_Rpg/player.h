#pragma once
#include <string>

class player {
protected:
    std::string name;
    int job;
    int level;
    int hp;
    int mp;
    int power;
    int defence;

public:
    player(std::string name, int stat[], int job);
    virtual void printPlayerStatus() = 0;
    virtual void attack() = 0;

    void takeDamage(int damage);

    int getHP() const;
    int getMP() const;
    int getPower() const;
    int getDefence() const;
    int getJob() const;

    virtual ~player();
};