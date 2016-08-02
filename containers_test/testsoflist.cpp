#include "testsoflist.h"

TestsOfList::TestsOfList()
{
}

void TestsOfList::testListDouble(int steps)
{

    std::list<double>::iterator double_it;
    double temp;

    // ======== LIST OF DOUBLE ==========
    std::cout<<"            LIST OF DOUBLE "<<steps<<" ELEMENTS"<<std::endl;


    // -------FILL (push back) --------
    std::clock_t begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        m_listOfDouble.push_back(temp);
    }
    std::cout<<"Filling list of double on back gets "<< float( std::clock() - begin_time ) /  CLOCKS_PER_SEC<<" seconds. " <<std::endl;
    m_listOfDouble.clear();

    // -------FILL (push front) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        m_listOfDouble.push_front(temp);
    }
    std::cout<<"Filling list of double on front gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;
    m_listOfDouble.clear();

    // -------FILL (insert) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        double_it = m_listOfDouble.begin();
        temp = rand() % 1000;
        m_listOfDouble.insert(double_it, temp);
    }
    std::cout<<"Filling list of double in the middle gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;

    // -------SORT--------
    begin_time = std::clock();
    m_listOfDouble.sort();
    std::cout<<"Sorting list of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;

    // -------FIND---------
    double toFind = rand() % 1000;
    begin_time = std::clock();
    std::find(m_listOfDouble.begin(), m_listOfDouble.end(), toFind);
    std::cout<<"Finding element in  list of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;

}

void TestsOfList::testListBook(int steps)
{
    std::string title= "TitLe";
    std::string author= "aUtHHor";
    std::list<Book>::iterator book_it;
    int isbn;
    std::cout<<"            LIST OF BOOKS "<<steps<<" ELEMENTS"<<std::endl;


    // -------FILL (push back) --------
    std::clock_t begin_time = std::clock();
    for(int i=0; i<steps; i++){
        isbn = rand() % 1000;
        m_listOfBooks.push_back(Book(i,isbn,title,author,true));
    }
    std::cout<<"Filling list of books on back gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds."<<std::endl;
    m_listOfBooks.clear();

    // -------FILL (push front) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        isbn = rand() % 1000;
        m_listOfBooks.push_front(Book(i,isbn,title,author,true));
    }
    std::cout<<"Filling list of books on front gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds."<<std::endl;
    m_listOfBooks.clear();


     // -------FILL (insert) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        isbn = rand() % 1000;
        book_it = m_listOfBooks.begin();
        m_listOfBooks.insert(book_it, Book(i,isbn, title,author,true));
    }
    std::cout<<"Filling list of books in the middle gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds."<<std::endl;


    // -------SORT--------
    begin_time = std::clock();
    m_listOfBooks.sort([](Book lhs, Book rhs) { return lhs.getID() < rhs.getID();});
    std::cout<<"Sorting list of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;


    // -------FIND---------
    begin_time = std::clock();
    std::find_if(m_listOfBooks.begin(), m_listOfBooks.end(), [](Book book){return book.getID() == 60; });
    std::cout<<"Finding element in  list of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;

}
