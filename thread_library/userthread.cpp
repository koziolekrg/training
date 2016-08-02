#include "userthread.h"

UserThread::UserThread(BooksStorage *a_bookStorage)
    :m_bookStorage(a_bookStorage)
{
    moveToThread(this);
}

void UserThread::run()
{
    int result=0;
    int temp;
    while(true){
        sleep(1);
        m_randValue =  rand() % 2;
            if(result == 0){
                result = m_bookStorage->borrowBookToUser(m_randValue, this);
                sleep(rand() %4);
                if(result == 0)
                    m_bookStorage->returnBookToStorage(m_randValue,this);
            }
            if(result!=0){
                temp = m_bookStorage->borrowBookToUser(result, this);
                sleep(rand() %3);
                if(temp ==0)
                    m_bookStorage->returnBookToStorage(result,this);
                result = temp;
            }

    }
}
