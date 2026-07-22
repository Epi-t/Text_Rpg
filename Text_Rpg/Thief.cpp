#include "Thief.h"
#include <iostream>

using namespace std;

Thief::Thief(string name, int stat[]) : player(name, stat, 3) {
    this->power = this->power + 30;
}


void Thief::attack(monster* Monster) {
    int BeforeHP = Monster->getHP();
    cout << "[Thief] Stab with a dagger! -> " << getPower() / 5 - Monster->getDefence() << " ( X5 ) Damage to " << Monster->getMname() << "!\n";

    if (getPower() / 5 - Monster->getDefence() <= 0)
    {
        for (int i = 0; i < 5; i++)
        {
            Monster->setHp(Monster->getHP() - 1);
        }
    }
    else
    {
        for (int i = 0; i < 5; i++) {
            Monster->setHp(Monster->getHP() - getPower() / 5 + Monster->getDefence());
        }
    }
    cout << Monster->getMname() << "'s HP : " << BeforeHP << " -> " << Monster->getHP() << endl;

}

void Thief::printPlayerStatus() {
    cout << "------------------------------------\n";
    cout << "Name : " << name << " | " << "Job : Thief | " << "Lv." << level << "\n";
    cout << "HP : " << hp << " | MP : " << mp << " | Attack : " << power << " | Defense : " << defence << "\n";
    cout << "------------------------------------\n";
}