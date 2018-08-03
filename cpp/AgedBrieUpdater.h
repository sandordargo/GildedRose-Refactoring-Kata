/*
 * DefaultUpdater.h
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */

#ifndef AGEDBRIEUPDATER_H_
#define AGEDBRIEUPDATER_H_

#include "Updater.h"

class AgedBrieUpdater : public Updater {
public:
	AgedBrieUpdater(int& sellIn, int& quality);

	virtual ~AgedBrieUpdater();

	virtual void updateQuality();

	virtual void updateSellIn();
};

#endif /* AGEDBRIEUPDATER_H_ */
