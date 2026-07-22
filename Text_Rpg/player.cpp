#include "player.h"

player::player(std::string name, int stat[], int job) {
    this->name = name;
    this->hp = stat[0];
    this->mp = stat[1];
    this->power = stat[2];
    this->defence = stat[3];
    this->job = job;
    this->level = 1;
    this->exp = 0;
    this->maxexp = 100;
    this->maxhp = stat[0];
    this->maxmp = stat[1];
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
int player::getExp() const
{
    return exp;
}
int player::getMaxExp() const
{
    return maxexp;
}
int player::getLevel() const
{
    return level;
}
int player::getDamage() const {
    return Damage;
}
int player::getMaxHP() const {
    return maxhp;
}

int player::getMaxMP() const {
    return maxmp;
}


void player::setMaxHP(int maxhp) {
    this->maxhp = maxhp;
}

void player::setMaxMP(int maxmp) {
    this->maxmp = maxmp;
}

void player::setDamage(int newDamage) {
    Damage = newDamage;
}
void player::setExp(int exp)
{
    this->exp = exp;
}
void player::setMaxExp(int maxexp)
{
    this->maxexp = maxexp;
}
void player::setLevel(int level)
{
    this->level = level;
}
void player::setHP(int hp)
{
    this->hp = hp;
}
void player::setMP(int mp)
{
    this->mp = mp;
}
void player::setPower(int att)
{
    this->power = att;
}
void player::setDefence(int def)
{
    this->defence = def;
}

player::~player() {}