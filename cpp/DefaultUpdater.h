/*
 * DefaultUpdater.h
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */

#ifndef DEFAULTUPDATER_H_
#define DEFAULTUPDATER_H_

#include "Updater.h"

class DefaultUpdater : public Updater {
public:
	DefaultUpdater(int& sellIn, int& quality);

	virtual ~DefaultUpdater();

	virtual void updateQuality();

	virtual void updateSellIn();
};

#endif /* DEFAULTUPDATER_H_ */
