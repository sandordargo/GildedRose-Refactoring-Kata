/*
 * DefaultUpdater.h
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */

#ifndef BACKSTAGEPASSUPDATER_H_
#define BACKSTAGEPASSUPDATER_H_

#include "Updater.h"

class BackstagePassUpdater : public Updater {
public:
	BackstagePassUpdater(int& sellIn, int& quality);

	virtual ~BackstagePassUpdater();

	virtual void updateQuality();

	virtual void updateSellIn();
};

#endif /* BACKSTAGEPASSUPDATER_H_ */
