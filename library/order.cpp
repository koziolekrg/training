#include "order.h"

Order::Order(int a_idorder, int a_idperson, int a_idbook, bool a_status)
    :id_order(a_idorder)
    ,id_person(a_idperson)
    ,id_book(a_idbook)
    ,status(a_status)
{
}

void Order::show(std::shared_ptr<Itemstore> m_itemstore, std::shared_ptr<Personstore> m_personstore)
{
    std::cout<<std::endl;
    std::cout<<"==========================="<<std::endl;
    std::cout<<"ID ORDER:"<<id_order;
    std::cout<<" USER:";
    m_personstore->showUserName(id_person);
    std::cout<<" BOOK:";
    m_itemstore->showItemTitle(id_book);
    std::cout<<" STATUS:";
    if(status==0)
        std::cout<<"Borrowed";
    else
        std::cout<<"Returned";

    std::cout<<std::endl;

}

std::string Order::saveOrder()
{
    return std::to_string(id_book)+"-"+std::to_string(id_person)+"-"+std::to_string(status)+"-";
}

int Order::completeOrder(std::shared_ptr<Itemstore> m_itemstore, int a_idperson, int a_idorder)
{
    if(a_idperson == id_person && a_idorder==id_order && status == 0){
        status = !status;
        m_itemstore->changeStatus(id_book);
        return 1;
    }
    return 0;
}

void Order::showUser(std::shared_ptr<Itemstore> m_itemstore, std::shared_ptr<Personstore> m_personstore, int a_idperson)
{
    if(a_idperson == id_person && !status)
        show(m_itemstore,m_personstore);
}
