#ifndef TESTSOFDEQUE_H
#define TESTSOFDEQUE_H
#include <deque>
#include <cstdlib>
#include <iostream>
#include "book.h"
#include <ctime>
#include <algorithm>

class TestsOfDeque
{
private:
    std::deque<double> m_dequeOfDouble;
    std::deque<Book> m_dequeOfBooks;

public:
    TestsOfDeque();
    void testDequeBook(int);
    void testDequeDouble(int);

};

#endif // TESTSOFDEQUE_H
