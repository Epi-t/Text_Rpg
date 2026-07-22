#include "monster.h"


monster::monster(std::string name, int hp, int power, int defence,
    std::string dropItemName, int dropItemPrice, int expReward) {
    this->name = name;
    this->hp = hp;
    this->power = power;
    this->defence = defence;
    this->dropItemName = dropItemName;
    this->dropItemPrice = dropItemPrice;
    this->expReward = expReward; 
}

int monster::getHP() const { return hp; }
int monster::getPower() const { return power; }
int monster::getDefence() const { return defence; }
std::string monster::getMname() const { return name; }
std::string monster::getdropItemName() const { return dropItemName; }
int monster::getExpReward() const { return expReward; }
int monster::getDropItemPrice() const {
    return dropItemPrice;
}
void monster::takeDamage(int damage)
{
    hp -= damage;
    if (hp < 0) { hp = 0; }
}

void monster::setName(const std::string& newName) { name = newName; }
void monster::setHp(int newHp) { hp = newHp; }
void monster::setPower(int newPower) { power = newPower; }
void monster::setDefence(int newDefence) { defence = newDefence; }
void monster::setDropItemName(const std::string& newDropItemName) { dropItemName = newDropItemName; }
void monster::setDropItemPrice(int newDropItemPrice) { dropItemPrice = newDropItemPrice; }
void monster::setExpReward(int newExpReward) { expReward = newExpReward; }

monster::~monster() {}