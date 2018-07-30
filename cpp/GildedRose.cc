#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::processItem(Item & item)
{
	if (item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert" && item.name != "Sulfuras, Hand of Ragnaros") {
		item.updateSellIn();
		item.updateQuality();

	} else if (item.name == "Sulfuras, Hand of Ragnaros") {
		item.updateSellIn();
		item.updateQuality();
	} else if (item.name == "Aged Brie") {
		item.updateSellIn();
		item.updateQuality();
	} else if (item.name.substr(0, 16) == "Backstage passes") {
		item.updateSellIn();
		item.updateQuality();
	} else if (item.name.substr(0, 8) == "Conjured") {
		item.updateSellIn();
		item.updateQuality();
	} else {
		if(item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert"){
			if(item.quality > 0){
				if(item.name != "Sulfuras, Hand of Ragnaros"){
					item.quality = item.quality - 1;
				}
			}

		}
		else{
			if(item.quality < 50){
				item.quality = item.quality + 1;
				if(item.name == "Backstage passes to a TAFKAL80ETC concert"){
					if(item.sellIn < 11){
						if(item.quality < 50){
							item.quality = item.quality + 1;
						}
					}

					if(item.sellIn < 6){
						if(item.quality < 50){
							item.quality = item.quality + 1;
						}
					}

				}

			}

		}

		if(item.name != "Sulfuras, Hand of Ragnaros"){
			item.sellIn = item.sellIn - 1;
		}
		if(item.sellIn < 0){
			if(item.name != "Aged Brie"){
				if(item.name != "Backstage passes to a TAFKAL80ETC concert"){
					if(item.quality > 0){
						if(item.name != "Sulfuras, Hand of Ragnaros"){
							item.quality = item.quality - 1;
						}
					}

				}
				else{
					item.quality = item.quality - item.quality;
				}
			}
			else{
				if(item.quality < 50){
					item.quality = item.quality + 1;
				}
			}

		}
	}

}

void GildedRose::updateQuality() 
{
    for (Item & item: items)
    {
        processItem(item);
    }
}
