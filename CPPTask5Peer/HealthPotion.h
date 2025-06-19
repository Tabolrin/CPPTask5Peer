#pragma once
#include <string>
#include "Item.h"

using namespace std;

class HealthPotion : public Item
{
private:
    int HealAmount;
    
public:
    HealthPotion (string itemName, int healAmount);
    
    void DisplayInfo() override;
    void ActOn(Character& character) override;
    ~HealthPotion() override = default;
};
