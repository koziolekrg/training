#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item
{
private:
    int id;
    int ISBN;
    std::string title;
    bool isAvaible;
    std::string toSave;

public:
    Item(int a_id, std::string a_title, int a_ISBN, bool isAvaible);
    virtual~Item();
    virtual void show() const;
    void showTitle();
    void change();
    bool getStatus();
    virtual std::string saveItem();
    int getID();
    std::string getTitle();

};


#endif // ITEM_H
