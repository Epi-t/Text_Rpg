#pragma once
#include "monster.h"

class slime : public monster {
public:
    slime(std::string Mname, int Mstat[], std::string dropItemName, int dropItemPrice);
    void attack(player* Player) override;
};