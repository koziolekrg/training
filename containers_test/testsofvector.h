#ifndef TESTSOFVECTOR_H
#define TESTSOFVECTOR_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include "book.h"
#include <ctime>
#include <algorithm>

class TestsOfVector
{
private:
    std::vector<double> m_vectorOfDouble;
    std::vector<Book> m_vectorOfBooks;

public:
    TestsOfVector();
    void testVectorDouble(int );
    void testVectorBook(int );

};

#endif // TESTSOFVECTOR_H
