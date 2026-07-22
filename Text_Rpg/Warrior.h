#pragma once
#include "player.h"

class Warrior : public player {
public:
    Warrior(std::string name, int stat[]);
    void attack(monster* Monster) override;
    void printPlayerStatus() override;
};