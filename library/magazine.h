#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <vector>
#include <cstdio>
#include <iostream>

#include "item.h"

class Magazine : public Item
{
private:
    std::string publisher;

public:
    Magazine(int a_id, std::string a_title, int a_ISBN, std::string a_publisher, bool a_status);
    void show() const override;
};


#endif // MAGAZINE_H
