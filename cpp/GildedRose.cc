#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

void GildedRose::increaseQuality(Item &item)
{
	if (item.quality < 50){
		item.quality++;
	}
}

void GildedRose::decreaseQuality(Item &item)
{
	if (item.quality > 0 && item.name != "Sulfuras, Hand of Ragnaros"){
		item.quality--;
	}
}

void GildedRose::decreaseSellIn(Item &item)
{
	if (item.name != "Sulfuras, Hand of Ragnaros"){
		item.sellIn--;
	}
}

void GildedRose::updateQualityOfItem(Item &item)
{
	if (item.name == "Aged Brie" )
	{
			increaseQuality(item);
	}
	else if ( item.name == "Backstage passes to a TAFKAL80ETC concert")
	{
		increaseQuality(item);

		if (item.sellIn < 11)
		{
			increaseQuality(item);
		}

		if (item.sellIn < 6)
		{
			increaseQuality(item);
		}
	}
	else
	{
		decreaseQuality(item);
	}

	if (item.sellIn < 0)
	{
		if (item.name == "Aged Brie")
		{
			increaseQuality(item);
		}
		else if (item.name == "Backstage passes to a TAFKAL80ETC concert")
		{
			item.quality = 0;
		}
		else
		{
			decreaseQuality(item);
		}
	}
}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        decreaseSellIn(items[i]);
        updateQualityOfItem(items[i]);
     }
}
