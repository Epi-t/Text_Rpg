#pragma once
#include "player.h"

class Warrior : public player {
public:
    Warrior(std::string name, int stat[]);
    void attack() override;
    void printPlayerStatus() override;
};