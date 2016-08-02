#ifndef PERSONSTORE_H
#define PERSONSTORE_H

#include <vector>
#include <fstream>
#include "exception.h"
#include "user.h"

class Personstore
{
private:
    std::vector<Person*> personList;
    int id;
    std::fstream people;


public:
    void addUser(std::string);
    void showAll();
    void showUser(int);
    void savePersonstore();
    void showUserName(int);
    int getCount();

    Personstore();
    ~Personstore();
};


#endif // PERSONSTORE_H

