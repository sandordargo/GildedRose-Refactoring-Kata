/*
 * Item.h
 *
 *  Created on: Aug 1, 2018
 *      Author: sdargo
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <string>

using namespace std;

class Updater;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Updater* updater;

    Item(const Item& i);
    Item& operator=(const Item& i);

    Item(string name, int sellIn, int quality);
    ~Item();
    void updateItem();
};

#endif /* ITEM_H_ */
