#pragma once
#include "player.h"

class Thief : public player {
public:
    Thief(std::string name, int stat[]);
    void attack(monster* Monster) override;
    void printPlayerStatus() override;
};
