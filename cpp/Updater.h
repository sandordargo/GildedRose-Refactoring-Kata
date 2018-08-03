#ifndef UPDATER_H_
#define UPDATER_H_

class Updater {
public:
	Updater(int& sellIn, int& quality);
	virtual ~Updater();

	virtual void updateQuality() = 0;
	virtual void updateSellIn() = 0;

protected:
	int& _quality;
	int& _sellIn;
};

#endif
