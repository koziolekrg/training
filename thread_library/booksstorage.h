#ifndef BOOKSSTORAGE_H
#define BOOKSSTORAGE_H
#include "book.h"
#include <QVector>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <mutex>
class UserThread;

class BooksStorage
{
private:
    int id;
    QVector <Book*> vectorOfBooks;
    QMutex mutex;
    QWaitCondition *m_condition;

public:
    BooksStorage(QWaitCondition*);
    ~BooksStorage();
    void addBookToStorage( QString, QString);
    int borrowBookToUser(int, UserThread*);
    void returnBookToStorage(int,UserThread*);
    QString getTitleBooks(int a_ID);
    void getAvailability(int);

};

#endif // BOOKSSTORAGE_H
