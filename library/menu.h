#ifndef MENU_H
#define MENU_H
#include<memory>
#include "itemstore.h"
#include "personstore.h"
#include "orderstore.h"
#include "readfile.h"


enum MenuState{
    ERROR,
    ADD_USER,
    ADD_BOOK,
    MAKE_ORDER,
    RETURN_BOOK,
    SHOW_ALL_USERS,
    SHOW_ALL_BOOKS,
    SHOW_ALL_ORDERS,
    CHECK_ORDERS,
    EXIT,
    SORT_VIA_TITLE,
    SORT_VIA_ID
};


class Menu
{
private:
    int ID, isbn;
    MenuState menuStatus;
    std::string title, a_name, a_sname;
    std::shared_ptr<Itemstore> itemstore;
    std::shared_ptr<Personstore> personstore;
    std::shared_ptr<Orderstore>  orderstore;

    Readfile *file;
public:
    Menu();
    ~Menu();
    void showMenu();

};

#endif // MENU_H
