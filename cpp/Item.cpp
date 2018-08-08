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

Item::~Item() {
	delete updater;
}

Item& Item::operator=(const Item& i){
	this->name = i.name;
	this->quality = i.quality;
	this->sellIn = i.sellIn;
	this->updater = i.updater;
	return *this;
}


Item::Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)//, updater()
{
	updater = Updater::CreateUpdater(name, this->sellIn, this->quality);
}

void Item::updateItem() {
	updater->updateSellIn();
	updater->updateQuality();
}
