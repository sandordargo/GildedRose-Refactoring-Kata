/*
 * DefaultUpdater.cpp
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */

#include "AgedBrieUpdater.h"

AgedBrieUpdater::AgedBrieUpdater(int& sellIn, int& quality) : Updater(sellIn, quality) {}

AgedBrieUpdater::~AgedBrieUpdater() {};

void AgedBrieUpdater::updateQuality() {
	if (_quality < 50) {
		_quality++;
		if (_quality < 50 && _sellIn < 0) {
			_quality++;
		}
	}
}

void AgedBrieUpdater::updateSellIn() {
	_sellIn--;
}
