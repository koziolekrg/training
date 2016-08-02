#include "orderstore.h"

void Orderstore::addOrder(int a_personid, int a_bookid, bool a_status)
{
    id++;
    orderList.push_back(new Order(id, a_personid, a_bookid, a_status));
}

void Orderstore::showAll(std::shared_ptr<Itemstore> m_itemstore, std::shared_ptr<Personstore> m_personstore)
{
    for(auto order: orderList)
        order->show(m_itemstore, m_personstore);
}


Orderstore::Orderstore()
{
    id =0;
}

Orderstore::~Orderstore()
{
    for(auto item : orderList)
    {
        delete item;
    }
}

void Orderstore::saveOrderstore()
{
    try{
        orders.open("orders.txt", std::ios::out);
        if(!orders.is_open())
            throw Exception();

    }catch(Exception& e)
    {
        std::cout<<e.what();
    }
    for(auto order : orderList)
        orders<<order->saveOrder();

    orders.close();
}

void Orderstore::showUserOrders(std::shared_ptr<Itemstore> m_itemstore, std::shared_ptr<Personstore> m_personstore, int a_idperson)
{
    for( auto order: orderList)
        order->showUser(m_itemstore, m_personstore, a_idperson);
}

int Orderstore::endOrder(std::shared_ptr<Itemstore> m_itemstore,int a_idperson, int a_idorder)
{
    for(auto item : orderList)
    {
        if(item->completeOrder(m_itemstore, a_idperson, a_idorder))
            return 1;
    }
    return 0;
}
