#include "Weapon.h"
#include "Item.h"
#include "Character.h"
#include <string>
#include <iostream>

using namespace std;

Weapon::Weapon (string itemName, float weaponDamage) : Item(itemName), damage(weaponDamage) {}
    
void Weapon::DisplayInfo() { cout << name << " Dealt Damage for: " << damage << " HP" << endl; }

void Weapon::ActOn(Character& character)
{
    character.Health -= damage;
    
    cout << character.Name << " was hit for: " << damage << " HP, " 
         << character.Health << " HP remaining" << endl;
}
