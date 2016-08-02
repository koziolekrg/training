#include "testsofvector.h"

TestsOfVector::TestsOfVector()
{
}


void TestsOfVector::testVectorDouble(int steps)
{
    std::vector<double>::iterator double_it;
    double temp;

    // ======== vector OF DOUBLE ==========
    std::cout<<"            vector OF DOUBLE "<<steps<<" ELEMENTS"<<std::endl;


    // -------FILL (push back) --------
    std::clock_t begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        m_vectorOfDouble.push_back(temp);
    }
    std::cout<<"Filling vector of double on back gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds. " <<std::endl;
    m_vectorOfDouble.clear();


    // -------FILL (push front) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        m_vectorOfDouble.insert(m_vectorOfDouble.begin(),temp);
    }
    std::cout<<"Filling vector of double on front gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;
    m_vectorOfDouble.clear();


    // -------FILL (insert) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        double_it = m_vectorOfDouble.begin();
        temp = rand() % 1000;
        m_vectorOfDouble.insert(double_it + i/2, temp);
    }
    std::cout<<"Filling vector of double in the middle gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;


    // -------SORT--------
    begin_time = std::clock();
    std::sort(m_vectorOfDouble.begin(),m_vectorOfDouble.end(),[](double ld, double rd){return ld<rd;});
    std::cout<<"Sorting vector of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;

    // -------FIND---------
    double toFind = rand() % 1000;
    begin_time = std::clock();
    std::find(m_vectorOfDouble.begin(), m_vectorOfDouble.end(), toFind);
    std::cout<<"Finding element in  vector of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;

}

void TestsOfVector::testVectorBook(int steps)
{
    std::vector<Book>::iterator book_it;
    std::string title= "TitLe";
    std::string author= "aUtHHor";
    std::cout<<"            vector OF BOOKS "<<steps<<" ELEMENTS"<<std::endl;
    int temp;

    // -------FILL (push back) --------
    std::clock_t begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        m_vectorOfBooks.push_back(Book(i,temp, title,author,true));
    }
    std::cout<<"Filling vector of books on back gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds."<<std::endl;
    m_vectorOfBooks.clear();

    // -------FILL (push front) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        m_vectorOfBooks.insert(m_vectorOfBooks.begin(), Book(i,temp, title,author,true));
    }
    std::cout<<"Filling vector of books on front gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds."<<std::endl;
    m_vectorOfBooks.clear();

    // -------FILL (insert) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        book_it = m_vectorOfBooks.begin();
        m_vectorOfBooks.insert(book_it+i/2, Book(i,temp, title,author,true));
    }
    std::cout<<"Filling vector of books in the middle gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds."<<std::endl;


    // -------SORT--------
    begin_time = std::clock();
    std::sort(m_vectorOfBooks.begin(), m_vectorOfBooks.end(),[](Book lhs, Book rhs) { return lhs.getID() < rhs.getID() ;});
    std::cout<<"Sorting vector of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;


    // -------FIND---------
    double toFind = rand() % 1000;
    begin_time = std::clock();
    //std::find_if(m_vectorOfBooks.begin(), m_vectorOfBooks.end(), [](Book book, double toFind){return book.getID() == 250; });
    std::cout<<"Finding element in  vector of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;

}



