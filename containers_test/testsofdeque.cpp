#include "testsofdeque.h"

TestsOfDeque::TestsOfDeque()
{
}

void TestsOfDeque::testDequeDouble(int steps)
{
    std::deque<double>::iterator double_it;
    double temp;

    std::cout<<"            deque OF DOUBLE "<<steps<<" ELEMENTS"<<std::endl;

    // -------FILL (push back) --------
    std::clock_t begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        m_dequeOfDouble.push_back(temp);
    }
    std::cout<<"Filling deque of double on back gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds. " <<std::endl;
    m_dequeOfDouble.clear();


    // -------FILL (push front) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        m_dequeOfDouble.push_front(temp);
    }
    std::cout<<"Filling deque of double on front gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;
    m_dequeOfDouble.clear();

    // -------FILL (insert) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        double_it = m_dequeOfDouble.begin()+i/2;
        temp = rand() % 1000;
        m_dequeOfDouble.insert(double_it, temp);
    }
    std::cout<<"Filling deque of double in the middle gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;


    // -------SORT--------
    begin_time = std::clock();
    std::sort(m_dequeOfDouble.begin(),m_dequeOfDouble.end(),[](double ld, double rd){return ld<rd;});
    std::cout<<"Sorting deque of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;


    // -------FIND---------
    double toFind = rand() % 1000;
    begin_time = std::clock();
    std::find(m_dequeOfDouble.begin(), m_dequeOfDouble.end(), toFind);
    std::cout<<"Finding element in  deque of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;
}

void TestsOfDeque::testDequeBook(int steps)
{

    std::string title= "TitLe";
    std::string author= "aUtHHor";
    std::deque<Book>::iterator book_it;
    int temp;
    std::cout<<"            deque OF BOOKS "<<steps<<" ELEMENTS"<<std::endl;
    // -------FILL (push back) --------
    std::clock_t begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        m_dequeOfBooks.push_back(Book(i,temp,title,author,true));
    }
    std::cout<<"Filling deque of books on back gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds."<<std::endl;
    m_dequeOfBooks.clear();


    // -------FILL (push front) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        m_dequeOfBooks.push_front(Book(i,temp,title,author,true));
    }
    std::cout<<"Filling deque of books on front gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds."<<std::endl;
    m_dequeOfBooks.clear();

    // -------FILL (insert) --------
    begin_time = std::clock();
    for(int i=0; i<steps; i++){
        temp = rand() % 1000;
        book_it = m_dequeOfBooks.begin()+i/2;
        m_dequeOfBooks.insert(book_it, Book(i,temp,title,author,true));
    }
    std::cout<<"Filling deque of books in the middle gets "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds."<<std::endl;

    // -------SORT--------
    begin_time = std::clock();
    std::sort(m_dequeOfBooks.begin(), m_dequeOfBooks.end(),[](Book  lhs, Book rhs) { return lhs.getID() < rhs.getID();});
    std::cout<<"Sorting deque of double "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;


    // -------FIND---------
    begin_time = std::clock();
    std::find_if(m_dequeOfBooks.begin(), m_dequeOfBooks.end(), [](Book bl){return bl.getID() == 50; });
    std::cout<<"Finding element in  deque of book "<< float( std::clock () - begin_time ) /  CLOCKS_PER_SEC<<" seconds.  " <<std::endl;


}
