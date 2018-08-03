/*
 * DefaultUpdater.h
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */

#ifndef CONJUREDITEMUPDATER_H_
#define CONJUREDITEMUPDATER_H_

#include "Updater.h"

class ConjuredItemUpdater : public Updater {
public:
	ConjuredItemUpdater(int& sellIn, int& quality);

	virtual ~ConjuredItemUpdater();

	virtual void updateQuality();

	virtual void updateSellIn();
};

#endif /* CONJUREDITEMUPDATER_H_ */
