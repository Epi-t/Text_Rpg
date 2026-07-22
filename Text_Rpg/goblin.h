#pragma once
#include "monster.h"

class goblin : public monster {
public:
    goblin();
    void attack(player* Player) override;
};