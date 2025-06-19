#include "HealthPotion.h"
#include "Item.h"
#include "Character.h"
#include <string>
#include <iostream>

using namespace std;

HealthPotion::HealthPotion(string itemName, int healAmount) : Item(itemName), HealAmount(healAmount) {}

void HealthPotion::DisplayInfo() override { cout << name << " Healed for: " << HealAmount << " HP" << endl; }

void HealthPotion::ActOn(Character& character)
{
    character.Health += HealAmount;
    
    cout << character.Name << " was healed for: " << HealAmount << " HP, " 
         << character.Health << " HP remaining" << endl;
}
