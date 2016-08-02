#ifndef ORDERSTORE_H
#define ORDERSTORE_H

#include <vector>
#include <memory>
#include "order.h"
#include "itemstore.h"
#include "personstore.h"
#include "exception.h"

class Orderstore
{
private:
    std::vector<Order*> orderList;
    int id;
    std::fstream orders;


public:
    void showUserOrders(std::shared_ptr<Itemstore> m_itemstore, std::shared_ptr<Personstore> m_personstore, int a_idperson);
    void showAll(std::shared_ptr<Itemstore> m_itemstore, std::shared_ptr<Personstore> m_personstore);
    void addOrder(int, int, bool);
    void saveOrderstore();
    int endOrder(std::shared_ptr<Itemstore> m_itemstore, int a_idperson, int a_idorder);
    Orderstore();
    ~Orderstore();

};


#endif // ORDERSTORE_H
