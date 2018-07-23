#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}

    void updateSellIn() {
    	sellIn--;
    }

    void updateQuality() {
    	if (quality > 0) {
			quality--;
			if (quality > 0 && sellIn < 0) {
				quality--;
			}
		}
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

