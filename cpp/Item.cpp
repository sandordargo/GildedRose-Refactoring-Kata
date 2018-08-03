/*
 * Item.cpp
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */


#include "Updater.h"
#include "SulfurasUpdater.h"
#include "AgedBrieUpdater.h"
#include "BackstagePassUpdater.h"
#include "ConjuredItemUpdater.h"
#include "DefaultUpdater.h"
#include "Item.h"



Item::Item(const Item& i):Item(i.name, i.sellIn, i.quality) {}

Item& Item::operator=(const Item& i){
	this->name = i.name;
	this->quality = i.quality;
	this->sellIn = i.sellIn;
}

Item::Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)//, updater()
{
	if (name == "Sulfuras, Hand of Ragnaros") {
		updater = new SulfurasUpdater(this->sellIn, this->quality);
	} else if(name == "Aged Brie") {
		updater = new AgedBrieUpdater(this->sellIn, this->quality);
	} else if (name.substr(0, 16) == "Backstage passes") {
		updater = new BackstagePassUpdater(this->sellIn, this->quality);
	} else if (name.substr(0, 8) == "Conjured") {
		updater = new ConjuredItemUpdater(this->sellIn, this->quality);
	} else {
		updater = new DefaultUpdater(this->sellIn, this->quality);
	}

}

void Item::updateItem() {
	updater->updateSellIn();
	updater->updateQuality();
}
