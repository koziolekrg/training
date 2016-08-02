#include <string>
#include <limits>
#include "menu.h"

using namespace std;


void Menu::showMenu()
{
    file->readBooks(itemstore);
    file->readUsers(personstore);
    file->readOrders(orderstore);

    personstore->showAll();
    std::cout<<"============================"<<std::endl;
    while(ID>personstore->getCount() || ID<=0){
       std::cout<<"Enter ID:";
        cin>>ID;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    ID = ID-1;

    while(menuStatus!=9)
    {
        menuStatus=ERROR;
        std::cout<<std::endl;
        std::cout<<"============================"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"1. Add user"<<std::endl;
        std::cout<<"2. Add book"<<std::endl;
        std::cout<<"3. Make order"<<std::endl;
        std::cout<<"4. Return book"<<std::endl;
        std::cout<<"5. Show all users" <<std::endl;
        std::cout<<"6. Show all books"<<std::endl;
        std::cout<<"7. Show all orders"<<std::endl;
        std::cout<<"8. Check your account"<<std::endl;
        std::cout<<"9. To exit"<<std::endl;

        int castToEnum;
        while(true)
        {
            cin>>castToEnum;
            if(castToEnum>0)
                break;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("clear");

            std::cout<<std::endl;
            std::cout<<"============================"<<std::endl;
            std::cout<<std::endl;
            std::cout<<"1. Add user"<<std::endl;
            std::cout<<"2. Add book"<<std::endl;
            std::cout<<"3. Make order"<<std::endl;
            std::cout<<"4. Return book"<<std::endl;
            std::cout<<"5. Show all users" <<std::endl;
            std::cout<<"6. Show all books"<<std::endl;
            std::cout<<"7. Show all orders"<<std::endl;
            std::cout<<"8. Check your account"<<std::endl;
            std::cout<<"9. To exit"<<std::endl;
        }
        system("clear");

        menuStatus= static_cast<MenuState>(castToEnum);
        switch(menuStatus){
        case MenuState::ADD_USER:
            std::cout<<"Login: ";
            cin>>a_name;
            personstore->addUser(a_name);
            break;
        case MenuState::ADD_BOOK:
            std::cout<<"Title: ";
            cin>>title;
            while(true)
            {
                std::cout<<"ISBN: ";
                cin>>isbn;
                if(isbn>0)
                    break;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("clear");
            }

            std::cout<<"Autor name: ";
            cin>>a_name;
            std::cout<<"Autor surname: ";
            cin>>a_sname;
            itemstore->addBook(title, isbn, a_name, a_sname, 1);
            break;
        case MenuState::MAKE_ORDER:
            itemstore->showAll();
            std::cout<<"================"<<std::endl;
            while(true)
            {
                std::cout<<"ID book to borrow: ";
                cin>>isbn;
                if(isbn>0 && isbn<=itemstore->getCount())
                    break;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("clear");
                itemstore->showAll();
                std::cout<<"================"<<std::endl;


            }

            if(itemstore->getStatus(isbn-1)) // check is book's status is available
            {
                orderstore->addOrder(ID,isbn-1,0);
                itemstore->changeStatus(isbn-1);
            }
            else
                std::cout<<"Sorry, this book is unavailable"<<std::endl;
            break;
        case MenuState::RETURN_BOOK:
            orderstore->showUserOrders(itemstore, personstore, ID);
            while(true)
            {
                std::cout<<"Choose order to return"<<std::endl;
                cin>>isbn;
                if(isbn>0)
                    break;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("clear");
            }
            if(orderstore->endOrder(itemstore, ID, isbn))
                std::cout<<"Book returned";
            else
                std::cout<<"Error: Wrong order ID";
            break;
        case MenuState::SHOW_ALL_USERS:
            personstore->showAll(); // show all users
            break;
        case MenuState::SHOW_ALL_BOOKS:
            itemstore->showAll(); // show all books
            break;
        case MenuState::SHOW_ALL_ORDERS:
            system("clear");
            orderstore->showAll(itemstore, personstore); // show all orders
            break;
        case MenuState::CHECK_ORDERS:
            orderstore->showUserOrders(itemstore, personstore, ID);//show user's books
            break;
        case MenuState::SORT_VIA_TITLE:
            itemstore->sortViaTitle();
            break;
        case MenuState::SORT_VIA_ID:
            itemstore->sortViaId();
            break;
        default:
            break;
        }
    }
}

Menu::Menu()
    :orderstore(new Orderstore())
    ,itemstore(new Itemstore())
    ,personstore(new Personstore())
    ,file(new Readfile(personstore))
{
}

Menu::~Menu()
{

    orderstore->saveOrderstore();
    itemstore->saveItemstore();
    personstore->savePersonstore();

    delete file;
}
