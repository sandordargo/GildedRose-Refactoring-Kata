/*
 * SulfurasUpdater.h
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */

#ifndef SULFURASUPDATER_H_
#define SULFURASUPDATER_H_

#include "Updater.h"

class SulfurasUpdater : public Updater {
public:
	SulfurasUpdater(int& sellIn, int& quality);

	virtual ~SulfurasUpdater();

	virtual void updateQuality();
	virtual void updateSellIn();
};


#endif /* SULFURASUPDATER_H_ */
