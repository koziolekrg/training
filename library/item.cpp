#include "item.h"

Item::Item(int a_id, std::string a_title, int a_ISBN, bool a_status)
    :id(a_id),
    ISBN(a_ISBN),
    title(a_title),
    isAvaible(a_status)
{

}

Item::~Item()
{

}

void Item::show() const
{
    std::cout<<"ID:"<<id<<" Title:"<<title<<" ISBN:"<<ISBN<<" Status:"<<isAvaible;
}

void Item::showTitle()
{
    std::cout<<title;
}

void Item::change()
{
    isAvaible=!isAvaible;
}

bool Item::getStatus()
{
    return isAvaible;
}

std::string Item::saveItem()
{
    return title+"-"+std::to_string(ISBN)+"-"+std::to_string(isAvaible);
}

int Item::getID()
{
    return id;
}

std::string Item::getTitle()
{
    return title;
}
