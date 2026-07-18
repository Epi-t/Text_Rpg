#include "monster.h"

monster::monster(std::string Mname, int Mstat[], std::string dropItemName, int dropItemPrice) {
    this->name = Mname;
    this->hp = Mstat[0];
    this->power = Mstat[1];
    this->defence = Mstat[2];
    this->dropItemName = dropItemName;
    this->dropItemPrice = dropItemPrice;
}
int monster::getHP() const
{
    return hp;
}
int monster::getPower() const
{
    return power;
}
int monster::getDefence() const
{
    return defence;
}
std::string monster::getMname() const
{
    return name;
}
std::string monster::getdropItemName() const
{
    return dropItemName;
}
void monster::takeDamage(int damage)
{
    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }
}


monster::~monster() {}