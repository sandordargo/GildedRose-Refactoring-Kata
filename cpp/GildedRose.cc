#include "GildedRose.h"

GildedRose::GildedRose(std::vector<Item> & items) : items(items)
{}

const std::string GildedRose::kBrie("Aged Brie");
const std::string GildedRose::kBackstagePass("Backstage passes to a TAFKAL80ETC concert");
const std::string GildedRose::kSulfuras("Sulfuras, Hand of Ragnaros");

void GildedRose::increaseQuality(Item &item)
{
	if (item.quality < 50){
		item.quality++;
	}
}

void GildedRose::decreaseQuality(Item &item)
{
	if (item.quality > 0 && item.name != kSulfuras) {
		item.quality--;
	}
}

void GildedRose::decreaseSellIn(Item &item)
{
	if (item.name != kSulfuras) {
		item.sellIn--;
	}
}

void GildedRose::updateAttributesOfItem(Item &item)
{
	if (item.name == kBrie) {updateBrie(item);}
	else if (item.name == kBackstagePass) {updateBackstagePass(item);}
	else if (item.name == kSulfuras) {updateSulfuras(item);}
	else {defaultUpdate(item);}
}

void GildedRose::defaultUpdate(Item &item)
{
	decreaseQuality(item);
	if (item.sellIn < 0) {decreaseQuality(item);}
}

void GildedRose::updateBrie(Item &item)
{
	increaseQuality(item);
	if (item.sellIn < 0)
	{
		increaseQuality(item);
	}
}

void GildedRose::updateBackstagePass(Item &item)
{
	increaseQuality(item);
	if (item.sellIn < 11) {increaseQuality(item);}
	if (item.sellIn < 6) {increaseQuality(item);}
	if (item.sellIn < 0) {item.quality = 0;}
}

void GildedRose::updateSulfuras(Item &item) {(void)0;}


void GildedRose::updateAttributes()
{
    for (int i = 0; i < items.size(); i++)
    {
        decreaseSellIn(items[i]);
        updateAttributesOfItem(items[i]);
     }
}
