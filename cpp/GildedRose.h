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
    void updateAttributes();
private:
    void decreaseQuality(Item &item);
	void decreaseSellIn(Item &item);
	void increaseQuality(Item &item);
	void updateQualityOfItem(Item &item);
	void updateBrie(Item &item);
	void updateBackstagePass(Item &item);
	void updateSulfuras(Item &item);
	void defaultUpdate(Item &item);
};

