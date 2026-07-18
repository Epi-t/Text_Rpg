#include "player.h"

player::player(std::string name, int stat[], int job) {
    this->name = name;
    this->hp = stat[0];
    this->mp = stat[1];
    this->power = stat[2];
    this->defence = stat[3];
    this->job = job;
    this->level = 1;
}

void player::takeDamage(int damage)
{
    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }
}
int player::getHP() const
{
    return hp;
}
int player::getMP() const
{
    return mp;
}
int player::getPower() const
{
    return power;
}
int player::getDefence() const
{
    return defence;
}
int player::getJob() const
{
    return job;
}
player::~player() {}