#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::processItem(Item & item)
{
	item.updateSellIn();
	item.updateQuality();
}

void GildedRose::updateQuality() 
{
    for (Item & item: items)
    {
        processItem(item);
    }
}
