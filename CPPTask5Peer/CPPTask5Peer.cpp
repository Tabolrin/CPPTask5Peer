#include "Item.h"
#include "Weapon.h"
#include "HealthPotion.h"
#include "Character.h"
#include <iostream>

using namespace std;

#define DEFAULT_ITEM_COUNT 3

int main(int argc, char* argv[])
{
    Item** inventory = new Item*[DEFAULT_ITEM_COUNT];
    int i = 0;
    
    do
    {
        int itemType;
        
        cout << "Please choose an item to add to your inventory:" << endl;
        cout << "1. Weapon" << endl;
        cout << "2. Health Potion" << endl;

        cin >> itemType;
        cin.ignore();

        switch (itemType)
        {
            case 1:
            {
                string weaponName;
                float weaponDamage;
            
                cout << "Enter the name of the weapon: ";
                getline(cin, weaponName);
                cin.ignore();
            
                cout << "Enter the damage of the weapon: ";
                cin >> weaponDamage;
                cin.ignore();
            
                Weapon* weapon = new Weapon(weaponName, weaponDamage);

                inventory[i] = dynamic_cast<Item*>(weapon);
                ++i;
                    
                break;
            }

            case 2:
            {
                string potionName;
                int healAmount;
            
                cout << "Enter the name of the health potion: ";
                getline(cin, potionName);
                cin.ignore();
            
                cout << "Enter the heal amount of the health potion: ";
                cin >> healAmount;
                cin.ignore();
            
                HealthPotion* potion = new HealthPotion(potionName, healAmount);

                inventory[i] = dynamic_cast<Item*>(potion);
                ++i;
                    
                break;
            }

            default:
            {
                cout << "Invalid item type!" << endl;   
            }
        }
    }while (i < DEFAULT_ITEM_COUNT);

    for (int j = 0; j < DEFAULT_ITEM_COUNT; ++j) 
        inventory[j]->DisplayInfo();
    

    Character player("Player", 100);
    Character enemy("Enemy", 100);

    int j = 0;
    
    do
    {
        string target;
        cout << "Apply item \"" << inventory[j]->name << "\" to which character? (player/enemy): ";
        cin >> target;

        if (target == "player")
        {
            inventory[j]->ActOn(player);
            ++j;
        }
        else if (target == "enemy")
        {
            inventory[j]->ActOn(enemy);
            ++j;
        }
        else
            cout << "Invalid target." << endl;
        
    }while (j < DEFAULT_ITEM_COUNT);

    
    for (int i = 0; i < DEFAULT_ITEM_COUNT; ++i) 
        delete inventory[i];
    
    delete[] inventory;
    
    return 0;
}
