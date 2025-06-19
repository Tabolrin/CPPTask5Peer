#pragma once
#include "Item.h"

class Weapon : public Item
{
private:
    float damage;
    
public:
    Weapon (string itemName, float weaponDamage);
    
    void DisplayInfo() override;
    void ActOn(Character& character) override;
    ~Weapon() override = default; 
};
