#ifndef USER_H
#define USER_H

#include "person.h"

class User : public Person
{
private:
   std::vector<int> listOfBooks;

public:
    User(int a_id, std::string a_name);
    std::string savePerson() override;

     void show() const;
};


#endif // USER_H
