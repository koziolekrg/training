
#include "book.h"

Book::Book(int a_ID, QString a_title, QString a_author, bool a_isAvailable)
    :m_ID(a_ID)
    ,m_title(a_title)
    ,m_author(a_author)
    ,m_isAvailable(a_isAvailable)
{
}

void Book::changeAvailability()
{
    m_isAvailable = !m_isAvailable;
}

QString Book::getBookTitle()
{
    return m_title;
}

bool Book::getBookStatus()
{
    return m_isAvailable;
}
