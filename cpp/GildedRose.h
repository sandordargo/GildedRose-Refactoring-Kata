#include <string>
#include <vector>

class Item
{
public:
	std::string name;
    int sellIn;
    int quality;
    Item(std::string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)
    {}
};

class GildedRose
{
	static const std::string kBrie;
	static const std::string kBackstagePass;
	static const std::string kSulfuras;

public:
	std::vector<Item> & items;
    GildedRose(std::vector<Item> & items);
    void increaseQuality(Item &item);
    void decreaseQuality(Item &item);
    void decreaseSellIn(Item &item);
    void updateAttributesOfItem(Item &item);
    void updateAttributes();
};

