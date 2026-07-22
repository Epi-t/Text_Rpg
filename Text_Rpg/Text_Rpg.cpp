#include <iostream>
#include <string>
#include <cstdlib>
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "slime.h"
#include "goblin.h"
#include "skeleton.h" 
#include "orc.h"
#include "dragon.h"
#include "inventory.h" 
#include <vector>      
#include <map>
#include "item.h"
#include <algorithm>
#include "potion.h"
#include "Text_Rpg.h"

using namespace std;

struct room {
    int roomNumber;
    bool isC;
    unique_ptr<monster> Monster;
};

struct Ingredient {
    string name;
    int count;
};

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}

void printStatus(string name, int stat[])
{
    cout << "===========================\n";
    cout << name << "'s " << "Stats\n";
    cout << "===========================\n";
    cout << "HP : " << stat[0] << " MP : " << stat[1] << "\n";
    cout << "Attack : " << stat[2] << " defense : " << stat[3] << "\n";
    cout << "===========================\n";
}

void alchemyworkshop()
{
    cout << "\n=== Potion Shop ===\n";
    cout << "1. Show all recipes\n";
    cout << "2. Search by potion name\n";
    cout << "3. Search by ingredient\n";
    cout << "4. Check Potion Stock\n";
    cout << "5. Dispense Potion\n";
    cout << "6. Return Potion\n";
    cout << "0. Go back to Main Menu\n";
    cout << "===================\n";
}

bool BattleLogic(std::string& name, monster* Monster, player* Player, int& choose, inventory<Item>& myInventory, std::string& dummy)
{
    cout << "[ Battle Start! ] " << name << " vs " << Monster->getMname() << "\n\n";
    bool isWin = false;

    while (Player->getHP() > 0 && Monster->getHP() > 0)
    {
        bool turnEnded = false;

        while (!turnEnded)
        {
            cout << "--- Player Turn ---\n";
            cout << "1. Attack\n";
            cout << "2. Use Item\n";
            cout << "Choose : ";
            cin >> choose;

            switch (choose) {
            case 1:
                Player->attack(Monster);
                turnEnded = true;
                break;
            case 2:
                cout << "\n[ inventory ]\n";

                if (myInventory.GetSize() == 0) {
                    cout << "* Inventory is empty!\n\n";
                    break;
                }

                for (int i = 0; i < myInventory.GetSize(); i++) {
                    cout << i + 1 << ". ";
                    myInventory[i].PrintInfo();
                    cout << "\n";
                }
                cout << "0. Cancel (Go back)\n";
                cout << "Choose the Use item : ";

                int itemChoice;
                cin >> itemChoice;
                cout << "\n";

                if (itemChoice == 0) {
                    cout << "* Cancelled item usage.\n\n";
                    break;
                }
                else if (itemChoice > 0 && itemChoice <= myInventory.GetSize()) {

                    string itemName = myInventory[itemChoice - 1].getname();

                    if (itemName == "HPPotion") {
                        int oldHP = Player->getHP();
                        Player->setHP(min(Player->getHP() + 50, Player->getMaxHP()));
                        cout << "* You used a HP Potion!\n";
                        cout << "* Your HP increased: " << oldHP << " -> " << Player->getHP() << "\n";
                        myInventory.RemoveItemAt(itemChoice - 1);
                        turnEnded = true;
                    }
                    else if (itemName == "MPPotion") {
                        int oldMP = Player->getMP();
                        Player->setMP(min(Player->getMP() + 50, Player->getMaxMP()));
                        cout << "* You used a MP Potion!\n";
                        cout << "* Your MP increased: " << oldMP << " -> " << Player->getMP() << "\n";
                        myInventory.RemoveItemAt(itemChoice - 1);
                        turnEnded = true;
                    }
                    else {
                        cout << "* You can't use this item in battle!\n\n";
                    }
                }
                else {
                    cout << "* Wrong input!\n\n";
                }
                break;
            default:
                cout << "* Wrong input!\n\n";
                break;
            }
        }

        if (Monster->getHP() <= 0)
        {
            cout << "\n" << Monster->getMname() << " (Dead)\n";
            isWin = true;
        }
        else
        {
            cout << "\n--- " << Monster->getMname() << "'s Turn ---\n";
            Monster->attack(Player);
        }

        if (!isWin && Player->getHP() > 0)
        {
            cout << "\n[Press Enter to go to the next turn...]\n";
            cin.ignore();
            getline(cin, dummy);
        }
    }

    if (isWin)
    {

        Player->setExp(Player->getExp() + Monster->getExpReward());
        cout << "\n* Victory!\n";
        cout << "* +" << Monster->getExpReward() << " EXP! (EXP : " << Player->getExp() << " / " << Player->getMaxExp() << ")\n";
        cout << "-> Got : " << Monster->getdropItemName() << "!\n";
        cout << "Saved to inventory\n";

        myInventory.AddItem(Item(Monster->getdropItemName(), Monster->getDropItemPrice()));


        if (Player->getExp() >= Player->getMaxExp())
        {
            cout << "... Level up condition met\n";
            cout << "  -> Level up! Lv." << Player->getLevel() << " -> Lv." << Player->getLevel() + 1 << endl;
            Player->setExp(0);
            Player->setMaxExp(Player->getMaxExp() + 25);
            Player->setLevel(Player->getLevel() + 1);
            Player->setMaxHP(Player->getMaxHP() + 10);
            Player->setMaxMP(Player->getMaxMP() + 10);
            Player->setHP(Player->getHP() + 10);
            Player->setMP(Player->getMP() + 10);
            Player->setPower(Player->getPower() + 5);
            Player->setDefence(Player->getDefence() + 5);
            cout << "HP +10, MP +10, Attack +5, Defence +5\n";
        }
        return true;
    }
    else
    {
        cout << "\n* You Lose...\n";
        return false;
    }
}


int main()
{
    string name;

    const int SIZE = 4;
    int stat[SIZE] = { 0 };

    player* Player = nullptr;
    monster* Monster = nullptr;
    vector<room> rooms;
    inventory<Item> myInventory(10);
    map<string, vector<Ingredient>> recipeDB;

    recipeDB["HPPotion"] = { {"Herb", 1}, {"Clean Water", 1} };
    recipeDB["StaminaPotion"] = { {"Herb", 1}, {"Berry", 1} };

    cout << "===========================\n";
    cout << "           Welcome\n";
    cout << "===========================\n";
    cout << "Enter your name: ";
    cin >> name;
    cout << "===========================\n";
    cout << "Your name is " << name << "\n";
    cout << "===========================\n";

    cout << "Enter your HP and MP : ";
    while (true)
    {
        cin >> stat[0] >> stat[1];
        if (stat[0] > 49 && stat[1] > 49) break;
        cout << "HP or MP is Too Low. Try again.\n";
    }

    cout << "===========================\n";
    cout << "Enter your Attack and Defense : ";
    while (true)
    {
        cin >> stat[2] >> stat[3];
        if (stat[2] > 29 && stat[3] > 29) break;
        cout << "Attack or Defense is Too Low. Try again.\n";
    }
    cout << "===========================\n";
    system("cls");
    printStatus(name, stat);

    int HP_Potion;
    int MP_Potion;
    setPotion(3, &HP_Potion, &MP_Potion);

    int choose = 0;
    bool isGameStart = false;

    cout << "* You received " << HP_Potion << " HP Potions and " << MP_Potion << " MP Potions.\n";
    cout << "===========================\n";
    cout << "< Character Upgrade >\n";
    cout << "1. HP UP    2. MP UP    3. Attack x2\n";
    cout << "4. Defense x2  5. Show Stats  0. Start Game\n";
    cout << "===========================\n";

    while (!isGameStart) {
        cout << "Choose : (0 ~ 5) ";
        cin >> choose;

        switch (choose) {
        case 1:
            if (HP_Potion > 0) {
                HP_Potion--;
                cout << "* Your HP increased by 20. (Remaining: " << HP_Potion << ")\n";
                stat[0] += 20;
            }
            else cout << "* Out of HP potions! \n";
            break;
        case 2:
            if (MP_Potion > 0) {
                MP_Potion--;
                cout << "* Your MP increased by 20. (Remaining: " << MP_Potion << ")\n";
                stat[1] += 20;
            }
            else cout << "* Out of MP potions! \n";
            break;
        case 3:
            cout << "* Attack has doubled.\n";
            stat[2] *= 2;
            break;
        case 4:
            cout << "* Defense has doubled.\n";
            stat[3] *= 2;
            break;
        case 5:
            printStatus(name, stat);
            break;
        case 0:
            cout << "Let's start the game!\n";
            isGameStart = true;
            for (int i = 0; i < HP_Potion; i++) {
                myInventory.AddItem(Item("HPPotion", 10));
                myInventory.ReturnPotion("HPPotion");
            }
            for (int i = 0; i < MP_Potion; i++) {
                myInventory.AddItem(Item("MPPotion", 10));
                myInventory.ReturnPotion("MPPotion");
            }
            break;
        default:
            cout << "That's an incorrect input!\n";
            break;
        }
    }
    system("cls");

    cout << "< Job Selection >\n";
    cout << name << ", choose your job!\n";
    cout << "1. Warrior   2. Mage   3. Thief   4. Archer\n";
    cout << "Choose : ";

    bool CJ = false;
    while (!CJ)
    {
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "* You became a Warrior! (HP +30)\n";
            Player = new Warrior(name, stat);
            CJ = true;
            break;
        case 2:
            cout << "* You became a Mage! (MP +30)\n";
            Player = new Magician(name, stat);
            CJ = true;
            break;
        case 3:
            cout << "* You became a Thief! (Attack +30)\n";
            Player = new Thief(name, stat);
            CJ = true;
            break;
        case 4:
            cout << "* You became a Archer! (Defence +30)\n";
            Player = new Archer(name, stat);
            CJ = true;
            break;
        default:
            cout << "That's an incorrect input!\n";
            break;
        }
    }

    Player->printPlayerStatus();
    cout << "\n[Press Enter to continue...]\n";
    cin.ignore();
    string dummy;
    getline(cin, dummy);
    system("cls");

    bool exitGame = false;
    int mainChoice = -1;

    while (!exitGame)
    {
        cout << "=== Main Menu ===\n";
        cout << "1. Enter Dungeon\n";
        cout << "2. Check Inventory\n";
        cout << "3. Potion Shop\n";
        cout << "0. Quit\n";
        cout << "=================\n";
        cout << "Choose : ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
        {
            system("cls");
            cout << "You Enter the Dungeon.\n";
            for (int i = 0; i < 4; i++)
            {

                if (i == 0) {
                    cout << "\n[ Room " << i + 1 << " ]\n";
                    Monster = new slime();
                }
                else if (i == 1) {
                    cout << "\n[ Room " << i + 1 << " ]\n";
                    Monster = new goblin(); 
                }
                else if (i == 2) {
                    cout << "\n[ Room " << i + 1 << " ]\n";
                    Monster = new skeleton();
                }
                else if (i == 3) {
                    cout << "\n[ Room " << i + 1 << " (BOSS) ]\n";
                    Monster = new dragon();
                }


                cout << "Wild " << Monster->getMname() << " appeared!\n";
                bool isWin = BattleLogic(name, Monster, Player, choose, myInventory, dummy);


                delete Monster;
                Monster = nullptr;


                if (isWin == true)
                {

                    if (i == 3) {
                        cout << "\n====================================\n";
                        cout << " Congratulations! You Win! \n";
                        cout << "====================================\n";
                        break;
                    }
                    else {
                        cout << "\nVictory! Moving on to the next room...\n";
                    }
                }
                else
                {
                    cout << "\nYou Lose... Back to Main Menu...\n";
                    break;
                }
            }



            cout << "\n[Press Enter to return to Main Menu...]\n";
            cin.ignore();
            getline(cin, dummy);
            system("cls");
            break;
        }


        case 2:
        {
            system("cls");
            cout << "[ Inventory (" << myInventory.GetSize() << "/" << myInventory.GetCapacity() << ") ]\n";

            if (myInventory.GetSize() == 0) {
                cout << "Inventory is empty.\n";
            }
            else {
                for (int i = 0; i < myInventory.GetSize(); i++)
                {
                    cout << i + 1 << ". ";
                    myInventory[i].PrintInfo();
                    cout << "\n";
                }
            }
            int sc;
            cout << "Do you want to organize your inventory? : (Y : 1) ";
            cin >> sc;
            switch (sc)
            {
            case 1:
                myInventory.sortItems();
                break;
            }

            cout << "\n[Press Enter to return to Main Menu...]\n";
            cin.ignore();
            getline(cin, dummy);
            system("cls");
            break;
        }

        case 3:
        {
            system("cls");
            int shopChoice = -1;
            string searchName;

            while (shopChoice != 0) {
                alchemyworkshop();
                cout << "Choose : ";
                cin >> shopChoice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Wrong input. Please enter a valid number.\n";
                    continue;
                }

                if (shopChoice == 1) {
                    cout << "\n[All Recipe Lists]\n";
                    for (const auto& recipe : recipeDB) {
                        cout << "-> " << recipe.first << " (";
                        for (size_t i = 0; i < recipe.second.size(); ++i) {
                            cout << recipe.second[i].name << " x" << recipe.second[i].count;
                            if (i < recipe.second.size() - 1) cout << ", ";
                        }
                        cout << ")\n";
                    }
                }
                else if (shopChoice == 2) {
                    cout << "Search potion name : ";
                    cin >> searchName;

                    auto it = recipeDB.find(searchName);
                    if (it != recipeDB.end()) {
                        cout << "-> " << it->first << " : ";
                        const auto& ingredients = it->second;
                        for (size_t i = 0; i < ingredients.size(); ++i) {
                            cout << ingredients[i].name << " x" << ingredients[i].count;
                            if (i < ingredients.size() - 1) cout << ", ";
                        }
                        cout << "\n";
                    }
                    else {
                        cout << "Recipe not found.\n";
                    }
                }
                else if (shopChoice == 3) {
                    cout << "Search ingredient: ";
                    cin >> searchName;
                    int foundCount = 0;

                    for (const auto& recipe : recipeDB) {
                        bool hasIngredient = false;
                        for (const auto& ing : recipe.second) {
                            if (ing.name == searchName) {
                                hasIngredient = true;
                                break;
                            }
                        }

                        if (hasIngredient) {
                            cout << "-> " << recipe.first << " (";
                            for (size_t i = 0; i < recipe.second.size(); ++i) {
                                cout << recipe.second[i].name << " x" << recipe.second[i].count;
                                if (i < recipe.second.size() - 1) cout << ", ";
                            }
                            cout << ")\n";
                            foundCount++;
                        }
                    }
                    cout << "Found " << foundCount << " recipes.\n";
                }
                else if (shopChoice == 4) {
                    cout << "Enter potion name to check stock: ";
                    cin >> searchName;
                    myInventory.GetStock(searchName);
                }
                else if (shopChoice == 5) {
                    cout << "Enter potion name to dispense: ";
                    cin >> searchName;
                    myInventory.DispensePotion(searchName);
                }
                else if (shopChoice == 6) {
                    cout << "Enter potion name to return: ";
                    cin >> searchName;
                    myInventory.ReturnPotion(searchName);
                }
                else if (shopChoice == 0) {
                    cout << "Leaving the potion workshop...\n";
                }
                else {
                    cout << "Wrong input.\n";
                }
            }

            system("cls");
            break;
        }

        case 0:
        {
            cout << "Leaving the game... Goodbye!\n";
            exitGame = true;
            break;
        }

        default:
        {
            cout << "Wrong input. Please choose again.\n";
            break;
        }

        }
    }

    if (Player != nullptr) {
        delete Player;
    }

    return 0;
}

