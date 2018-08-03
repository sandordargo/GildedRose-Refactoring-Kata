/*
 * DefaultUpdater.cpp
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */

#include "BackstagePassUpdater.h"

BackstagePassUpdater::BackstagePassUpdater(int& sellIn, int& quality) : Updater(sellIn, quality) {}

BackstagePassUpdater::~BackstagePassUpdater() {};

void BackstagePassUpdater::updateQuality() {
	if (_quality < 50) {
		_quality++;
		if (_sellIn < 10 && _sellIn >=5 && _quality < 50) {
			_quality++;
		}
		else if (_sellIn < 5 && _sellIn >=0 && _quality < 50) {
			_quality++;
			_quality++;
		}
	}
	if (_sellIn < 0) {
		_quality = 0;
	}
}

void BackstagePassUpdater::updateSellIn() {
	_sellIn--;
}
