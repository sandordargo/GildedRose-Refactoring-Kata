#ifndef UPDATER_H_
#define UPDATER_H_

#include <string>

class Updater {
public:
	Updater(int& sellIn, int& quality);
	virtual ~Updater();

	virtual void updateQuality() = 0;
	virtual void updateSellIn() = 0;
	static Updater* CreateUpdater(std::string name, int& sellIn, int& quality);

protected:
	int& _quality;
	int& _sellIn;
};

#endif
