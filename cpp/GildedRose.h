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
};

class GildedRose
{
	static const string kBrie;
	static const string kBackstagePass;
	static const string kSulfuras;

public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    void increaseQuality(Item &item);
    void decreaseQuality(Item &item);
    void decreaseSellIn(Item &item);
    void updateQualityOfItem(Item &item);
    void updateQuality();
};

