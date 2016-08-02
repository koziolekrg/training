#include <iostream>
#include "book.h"
#include <vector>
#include <deque>
#include <list>
#include "testsofdeque.h"
#include "testsoflist.h"
#include "testsofvector.h"

int HOW = 30000;
int main()
{

    TestsOfList testList;

    TestsOfVector testVector;

    TestsOfDeque testDeque;

   /* std::cout<<"============================================="<<std::endl;
    testList.testListDouble(HOW);
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    testList.testListBook(HOW);
    std::cout<<std::endl;
*/
    std::cout<<"============================================="<<std::endl;
    testDeque.testDequeDouble(HOW);
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    testDeque.testDequeBook(HOW);
    std::cout<<std::endl;
/*
    std::cout<<"============================================="<<std::endl;
    testVector.testVectorDouble(HOW);
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    testVector.testVectorBook(HOW);
    std::cout<<"============================================="<<std::endl;
*/

    return 0;
}





