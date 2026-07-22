#pragma once
#include<string>

class Item
{
private:
    std::string name;
    int price;

public:

    friend std::ostream& operator<<(std::ostream& os, const Item& item) {
        os << item.name;
        return os;
    }
    Item()
    {
        this->name = "Empty";
        this->price = 0;
    }

    Item(std::string dropItemName, int dropItemPrice)
    {
        this->name = dropItemName;
        this->price = dropItemPrice;
    }
    std::string getname() const
    {
        return name;
    }
    int getprice() const
    {
        return price;
    }
    void PrintInfo()
    {
        std::cout << name << " (" << price << "G)";
    }
    static bool compareByPrice(const Item& a, const Item& b)
    {
        if (a.getprice() < b.getprice())
        {
            return true;
        }
        else
        {
            return false;
        }

    }
        
};