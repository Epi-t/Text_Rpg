#pragma once
#include "monster.h"

class dragon : public monster {
public:
    dragon();
    void attack(player* Player) override;
};