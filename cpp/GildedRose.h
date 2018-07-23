#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Updater {
public:
	Updater(int& sellIn, int& quality) : _quality(quality), _sellIn(sellIn) {}
	virtual ~Updater() {};

	virtual void updateQuality() = 0;
	virtual void updateSellIn() = 0;

protected:
	int& _quality;
	int& _sellIn;
};

class DefaultUpdater : public Updater {
public:
	DefaultUpdater(int& sellIn, int& quality) : Updater(sellIn, quality) {}

	virtual ~DefaultUpdater() {};

	virtual void updateQuality() {
		if (_quality > 0) {
			_quality--;
			if (_quality > 0 && _sellIn < 0) {
				_quality--;
			}
		}
	}

	virtual void updateSellIn() {
		_sellIn--;
	}
};

class SulfurasUpdater : public Updater {
public:
	SulfurasUpdater(int& sellIn, int& quality) : Updater(sellIn, quality) {}

	virtual ~SulfurasUpdater() {};

	virtual void updateQuality() {}

	virtual void updateSellIn() {}
};

class AgedBrieUpdater : public Updater {
public:
	AgedBrieUpdater(int& sellIn, int& quality) : Updater(sellIn, quality) {}

	virtual ~AgedBrieUpdater() {};

	virtual void updateQuality() {
		if (_quality < 50) {
			_quality++;
			if (_quality < 50 && _sellIn < 0) {
				_quality++;
			}
		}
	}

	virtual void updateSellIn() {
		_sellIn--;
	}
};

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Updater* updater;

    Item(const Item& i):Item(i.name, i.sellIn, i.quality) {}
    Item& operator=(const Item& i){
    	this->name = i.name;
    	this->quality = i.quality;
    	this->sellIn = i.sellIn;
    }

    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)//, updater()
    {
    	if (name == "Sulfuras, Hand of Ragnaros") {
    		updater = new SulfurasUpdater(this->sellIn, this->quality);
    	} else if(name == "Aged Brie") {
    		updater = new AgedBrieUpdater(this->sellIn, this->quality);
    	} else {
    		updater = new DefaultUpdater(this->sellIn, this->quality);
    	}

    }

    void updateSellIn() {
    	updater->updateSellIn();
    }

    void updateQuality() {
    	updater->updateQuality();
    }
};



class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void updateQuality();
private:
    void processItem(Item & item);
};

