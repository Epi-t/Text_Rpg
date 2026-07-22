#pragma once
#include "monster.h"

class skeleton : public monster {
public:
    skeleton();
    void attack(player* Player) override;
};