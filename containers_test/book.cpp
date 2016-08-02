#include "book.h"

Book::Book(int a_id, int a_isbn, std::string a_title, std::string a_author, bool a_status)
    :m_id(a_id), m_isbn(a_isbn),  m_title(a_title), m_author(a_author),m_status(a_status)
{
}

int Book::getID()
{
    return m_isbn;
}
