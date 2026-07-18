

#pragma once
#include "player.h"

class Magician : public player {
public:
    Magician(std::string name, int stat[]);
    void attack() override;
    void printPlayerStatus() override;
};
