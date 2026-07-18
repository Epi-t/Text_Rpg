#include "slime.h"
#include "player.h"
#include "iostream"

using namespace std;


slime::slime(string Mname, int Mstat[], string dropItemName, int dropItemPrice) : monster(Mname, Mstat, dropItemName, dropItemPrice) {
}


void slime::attack(player* Player)
{
    
    if (Player == nullptr)
    {
        cout << "Wrong Attack." << endl;
        return;
    }

    int damage = 0;
    damage = power - Player->getDefence();

    if (damage <= 0)
    {
        damage = 1;
    }

    Player->takeDamage(damage);

    cout << name << " attack You!" << endl;
    cout << "Remaining HP : " << Player->getHP() << endl;
}