#ifndef BOOK_H
#define BOOK_H

#include "item.h"

class Book : public Item
{
private:
    std::string authorName;
    std::string authorSurname;

public:
    Book(int a_id, std::string a_title, int a_ISBN, std::string a_authorName, std::string a_authorSurname, bool a_status);
    void show() const override;
    std::string saveItem() override;
     ~Book(){}

};


#endif // BOOK_H
