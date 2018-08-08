/*
 * Updater.cpp
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

Updater::Updater(int& sellIn, int& quality) : _quality(quality), _sellIn(sellIn) {}

Updater::~Updater() {}

Updater* Updater::CreateUpdater(std::string name, int& sellIn, int& quality) {
	if (name == "Sulfuras, Hand of Ragnaros") {
		return new SulfurasUpdater(sellIn, quality);
	} else if(name == "Aged Brie") {
		return new AgedBrieUpdater(sellIn, quality);
	} else if (name.substr(0, 16) == "Backstage passes") {
		return new BackstagePassUpdater(sellIn, quality);
	} else if (name.substr(0, 8) == "Conjured") {
		return new ConjuredItemUpdater(sellIn, quality);
	}
	return new DefaultUpdater(sellIn, quality);
}

