#pragma once
#include <string>
class player;

class monster {
protected:
    std::string name;
    int hp;
    int power;
    int defence;
    std::string dropItemName;
    int dropItemPrice;

public:
    monster(std::string Mname, int Mstat[], std::string dropItemName, int dropItemPrice);
    virtual void attack(player* Player) = 0;
    std::string getMname() const;
    int getHP() const;
    int getPower() const;
    int getDefence() const;
    std::string getdropItemName() const;
    void takeDamage(int damage);

    virtual ~monster();

};