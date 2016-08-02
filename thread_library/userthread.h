#ifndef USERTHREAD_H
#define USERTHREAD_H
#include <QThread>
#include <memory>
#include <cstdlib>
#include "booksstorage.h"


class UserThread : public QThread
{
private:
     BooksStorage* m_bookStorage;
     int m_randValue;

public:
    UserThread(BooksStorage*);
    void run();

};

#endif // USERTHREAD_H
