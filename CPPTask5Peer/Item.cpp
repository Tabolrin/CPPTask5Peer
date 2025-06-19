#include "Item.h"
#include <string>
#include <iostream>

using namespace std;

Item::Item(string itemName) : name(itemName) {}

void Item::DisplayInfo() { cout << "Just an Item" << name << endl; }

void Item::ActOn(Character& character) { cout << "Item used, but nothing happened." << endl; }
