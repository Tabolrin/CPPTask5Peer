#pragma once
#include <string>
using namespace std;

class Item
{
public:
    string name;
    
    Item(string itemName);
    
    virtual void DisplayInfo();
    virtual void ActOn(class Character& character);
    virtual ~ Item() = default; 
};

