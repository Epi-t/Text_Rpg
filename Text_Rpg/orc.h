#pragma once
#include "monster.h"

class orc : public monster {
public:
    orc();
    void attack(player* Player) override;
};