#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book
{
private:
    int m_id;
    int m_isbn;
    std::string m_title;
    std::string m_author;
    bool m_status;
public:
    Book(int a_id,int  m_isbn, std::string a_title, std::string a_author, bool a_status);
    int getID();
};

#endif // BOOK_H
