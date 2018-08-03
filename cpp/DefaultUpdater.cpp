/*
 * DefaultUpdater.cpp
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */

#include "DefaultUpdater.h"

DefaultUpdater::DefaultUpdater(int& sellIn, int& quality) : Updater(sellIn, quality) {}

DefaultUpdater::~DefaultUpdater() {};

void DefaultUpdater::updateQuality() {
	if (_quality > 0) {
		_quality--;
		if (_quality > 0 && _sellIn < 0) {
			_quality--;
		}
	}
}

void DefaultUpdater::updateSellIn() {
	_sellIn--;
}
