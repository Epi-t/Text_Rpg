#include <iostream>
#include <string>
#include <cstdlib>
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "slime.h"
#include <vector>
#include <map>

using namespace std;

struct Ingredient {
    string name;
    int count;
};

void printStatus(string name, int stat[])
{
    cout << "===========================\n";
    cout << name << "'s " << "Stats\n";
    cout << "===========================\n";
    cout << "HP : " << stat[0] << " MP : " << stat[1] << "\n";
    cout << "Attack : " << stat[2] << " defense : " << stat[3] << "\n";
    cout << "===========================\n";
}

class Item
{
private:
    string name;
    int price;

public:
    Item(string dropItemName, int dropItemPrice)
    {
        this->name = dropItemName;
        this->price = dropItemPrice;
    }
    string getname()
    {
        return name;
    }
    int getprice()
    {
        return price;
    }
    void PrintInfo()
    {
        cout << name << " (" << price << "G)";
    }
};

void alchemyworkshop()
{
    cout << "\n=== Potion Shop ===\n";
    cout << "1. Show all recipes\n";
    cout << "2. Search by potion name\n";
    cout << "3. Search by ingredient\n";
    cout << "0. Go back to Main Menu\n";
    cout << "===================\n";
}

int main()
{

    string name;
    string Mname = "Slime";
    string dropItemName = "Slime Jelly";
    int dropItemPrice = 30;
    int Mstat[3] = { 30, 20, 10 };
    const int SIZE = 4;
    int stat[SIZE] = { 0 };

    player* Player = nullptr;
    monster* Monster = nullptr;
    vector<Item> inventory;
    map<string, vector<Ingredient>> recipeDB;


    recipeDB["HPPotion"] = { {"Herb", 1}, {"Clean Water", 1} };
    recipeDB["StaminaPotion"] = { {"Herb", 1}, {"Berry", 1} };

    cout << "===========================\n";
    cout << "          Welcome\n";
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

    int HP_Potion = 5;
    int MP_Potion = 5;
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
            break;
        default:
            cout << "That's an incorrect input!\n";
            break;
        }
    }
    system("cls");


    cout << "< Job Selection >\n";
    cout << name << ", choose your job!\n";
    cout << "1. Warrior   2. Mage   3. Rogue   4. Archer\n";
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

            Monster = new slime(Mname, Mstat, dropItemName, dropItemPrice);

            cout << "[ Battle Start! ] " << name << " vs " << Monster->getMname() << "\n\n";
            bool isWin = false;

            while (Player->getHP() > 0 && Monster->getHP() > 0)
            {
                cout << "--- Player Turn ---\n";
                Player->attack();
                int damageToMonster = Player->getPower() - Monster->getDefence();
                if (damageToMonster < 0) damageToMonster = 0; 

                cout << damageToMonster << " damage to " << Monster->getMname() << "!\n";
                Monster->takeDamage(damageToMonster);

                if (Monster->getHP() <= 0)
                {
                    cout << Monster->getMname() << " (Dead)\n";
                    isWin = true;
                }
                else
                {
                    cout << Monster->getMname() << " HP : " << Monster->getHP() << "\n";
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
                cout << "\n* Victory!\n";
                cout << "-> Got : " << Monster->getdropItemName() << "!\n";
                cout << "Saved to inventory\n";
                inventory.push_back(Item(dropItemName, dropItemPrice));
            }
            else
            {
                cout << "\n* You Lose...\n";
            }

        
            delete Monster;
            Monster = nullptr;

            cout << "\n[Press Enter to return to Main Menu...]\n";
            cin.ignore();
            getline(cin, dummy);
            system("cls");
            break;
        }

        case 2:
        {
            system("cls");
            int i = 1;
            cout << "[ Inventory (" << inventory.size() << "/10) ]\n";

            if (inventory.empty()) {
                cout << "Inventory is empty.\n";
            }
            else {
                for (auto item : inventory)
                {
                    cout << i << ". ";
                    item.PrintInfo();
                    cout << "\n";
                    i++;
                }
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