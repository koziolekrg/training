#ifndef TESTSOFLIST_H
#define TESTSOFLIST_H
#include <list>
#include <cstdlib>
#include <iostream>
#include "book.h"
#include <ctime>
#include <algorithm>

class TestsOfList
{
private:
    std::list<double> m_listOfDouble;
    std::list<Book> m_listOfBooks;

public:
    TestsOfList();
    void testListDouble(int);
    void testListBook(int);

};

#endif // TESTSOFLIST_H
