#include "magazine.h"

Magazine::Magazine(int a_id, std::string a_title, int a_ISBN, std::string a_publisher, bool a_status)
    :Item(a_id, a_title, a_ISBN, a_status),
      publisher(a_publisher)
{

}

void Magazine::show() const
{
    Item::show();
    std::cout<<" Publisher: "<<publisher<<std::endl;
}
