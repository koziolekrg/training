#ifndef READFILE_H
#define READFILE_H

#include <memory>
#include <fstream>
#include "itemstore.h"
#include "personstore.h"
#include "orderstore.h"
#include "exception.h"



class Readfile
{
private:
    std::fstream users, books, orders;
    std::string temp, title, a_name, a_sname;
    int i,isbn,id_book, id_users;
    bool status;
public:
    Readfile(std::shared_ptr<Personstore> m_personstore);
    ~Readfile();
    void readBooks(std::shared_ptr<Itemstore> itemstore);
    void readUsers(std::shared_ptr<Personstore> personstore);
    void readOrders(std::shared_ptr<Orderstore> orderstore);
};

#endif // READFILE_H
