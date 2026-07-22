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
    int expReward; 

public:

    monster(std::string name, int hp, int power, int defence,
        std::string dropItemName, int dropItemPrice, int expReward);
    virtual ~monster();

    virtual void attack(player* Player) = 0;


    std::string getMname() const;
    int getHP() const;
    int getPower() const;
    int getDefence() const;
    std::string getdropItemName() const;
    int getExpReward() const; 
    int getDropItemPrice() const;
    void takeDamage(int damage);


    void setName(const std::string& newName);
    void setHp(int newHp);
    void setPower(int newPower);
    void setDefence(int newDefence);
    void setDropItemName(const std::string& newDropItemName);
    void setDropItemPrice(int newDropItemPrice);
    void setExpReward(int newExpReward);

};