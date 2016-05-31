#include <gtest/gtest.h>

#include "GildedRose.h"

TEST(GildedRoseTest, NomralDecreaseForRandomItem) {
    vector<Item> items;
    items.push_back(Item("Foo", 10, 20));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ("Foo", app.items[0].name);
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(19, app.items[0].quality);
}

TEST(GildedRoseTest, NegativeSellinValue) {
    vector<Item> items;
    items.push_back(Item("Foo", -1, 20));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ("Foo", app.items[0].name);
    EXPECT_EQ(-2, app.items[0].sellIn);
    EXPECT_EQ(18, app.items[0].quality);
}

TEST(GildedRoseTest, ZeroQualityShouldNotGoNegative) {
    vector<Item> items;
    items.push_back(Item("Foo", 10, 0));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ("Foo", app.items[0].name);
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, AgedBrieIncreasesQuality) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", 10, 20));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ("Aged Brie", app.items[0].name);
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(21, app.items[0].quality);
}

TEST(GildedRoseTest, AgedBrieDoubleQualityIncreaseAfterNegativeSellinDate) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", -1, 20));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ("Aged Brie", app.items[0].name);
    EXPECT_EQ(-2, app.items[0].sellIn);
    EXPECT_EQ(22, app.items[0].quality);
}

TEST(GildedRoseTest, QualityStartsAboveFifty) {
    vector<Item> items;
    items.push_back(Item("Foo", 10, 51));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ("Foo", app.items[0].name);
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(50, app.items[0].quality);
}



TEST(GildedRoseTest, QualityCappedAtFifty) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", 10, 50));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ("Aged Brie", app.items[0].name);
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(50, app.items[0].quality);
}

TEST(GildedRoseTest, SulfurasDoesNotChange) {
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 10, 20));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(10, app.items[0].sellIn);
    EXPECT_EQ(20, app.items[0].quality);
}

TEST(GildedRoseTest, BackstagePassIncreaseQualityBy1MoreThan10Days) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(14, app.items[0].sellIn);
    EXPECT_EQ(21, app.items[0].quality);
}

TEST(GildedRoseTest, BackstagePassIncreaseQualityBy2Before10Days) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 20));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(22, app.items[0].quality);
}

TEST(GildedRoseTest, BackstagePassIncreaseQualityBy3LessThan5Days) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 20));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(4, app.items[0].sellIn);
    EXPECT_EQ(23, app.items[0].quality);
}

TEST(GildedRoseTest, BackstagePassQualityGoesZeroWithNegativeSellinDate) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 0, 20));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}


void example()
{
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Conjured Mana Cake", 3, 6));
    GildedRose app(items);
    app.updateQuality();
}
