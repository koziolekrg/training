#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QDebug>

class Book
{
private:
    int m_ID;
    QString m_title;
    QString m_author;
    bool m_isAvailable;

public:
    Book(int , QString, QString,bool);
    void changeAvailability();
    bool getBookStatus();
    QString getBookTitle();
};

#endif // BOOK_H
