#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <iostream>

class Person
{
private:
    int id;
    std::string name;

public:
    Person(int a_id, std::string a_name);
    virtual ~Person(){}
    void show() const;
    virtual std::string savePerson();
    void showName();


};


#endif // PERSON_H
