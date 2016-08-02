#ifndef ORDER_H
#define ORDER_H

#include <memory>
#include <vector>
#include <time.h>
#include "itemstore.h"
#include "personstore.h"

class Order
{
private:
    int id_order;
    int id_person;
    int id_book;
    bool status;

public:
    Order(int a_idorder, int a_idperson, int a_idbook, bool a_status);
    void show(std::shared_ptr<Itemstore> m_itemstore, std::shared_ptr<Personstore> m_personstore);
    int returnID();
    std::string saveOrder();
    void showUser(std::shared_ptr<Itemstore> m_itemstore, std::shared_ptr<Personstore> m_personstore, int a_idperson);
    int completeOrder(std::shared_ptr<Itemstore> m_itemstore, int a_idperson, int a_idorder);

};




#endif // ORDER_H
