/*
 * DefaultUpdater.cpp
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */

#include "ConjuredItemUpdater.h"

ConjuredItemUpdater::ConjuredItemUpdater(int& sellIn, int& quality) : Updater(sellIn, quality) {}

ConjuredItemUpdater::~ConjuredItemUpdater() {};

void ConjuredItemUpdater::updateQuality() {
	if (_quality > 0) {
		_quality--;
		if (_quality > 0) {
			_quality--;
		}
	}
}

void ConjuredItemUpdater::updateSellIn() {
	_sellIn--;
}
