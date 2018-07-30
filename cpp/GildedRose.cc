#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::processItems() 
{
    for (Item & item: items)
    {
    	item.updateItem();
    }
}
