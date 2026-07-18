#pragma once
#include "player.h"

class Archer : public player {
public:
    Archer(std::string name, int stat[]);
    void attack() override;
    void printPlayerStatus() override;
};