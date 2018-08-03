#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void processItems();
};

