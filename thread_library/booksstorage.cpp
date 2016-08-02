#include "booksstorage.h"
#include "userthread.h"

BooksStorage::~BooksStorage()
{
    for(auto book : vectorOfBooks)
        delete book;
}

BooksStorage::BooksStorage(QWaitCondition* a_condition)
    :m_condition(a_condition)
{
    id = 0;
}

void BooksStorage::addBookToStorage(QString a_title, QString a_author)
{
    vectorOfBooks.push_back(new Book(id, a_title, a_author, 1));
    id++;
}

int BooksStorage::borrowBookToUser(int a_ID, UserThread * userThread)
{

        mutex.lock();
        if(vectorOfBooks[a_ID]->getBookStatus()){
            vectorOfBooks[a_ID]->changeAvailability();
            qDebug()<<"User_"<<userThread->objectName().toInt()<<" borrowed "<<vectorOfBooks[a_ID]->getBookTitle();

           mutex.unlock();
            return 0;
        }
        else{
            qDebug()<<"User_"<<userThread->objectName().toInt()<<"waiting for "<<vectorOfBooks[a_ID]->getBookTitle();
            m_condition->wait(&mutex);

            mutex.unlock();
            return a_ID;
        }

}

void BooksStorage::returnBookToStorage(int a_ID,UserThread* userThread)
{
        mutex.lock();
        if(!vectorOfBooks[a_ID]->getBookStatus()){
            vectorOfBooks[a_ID]->changeAvailability();
            qDebug()<<"User_"<<userThread->objectName().toInt()<<" returned  "<<vectorOfBooks[a_ID]->getBookTitle();
            m_condition->wakeOne();
        }
       mutex.unlock();
}
