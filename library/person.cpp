#include "person.h"

Person::Person(int a_id, std::string a_name)
    :id(a_id),
    name(a_name)
{
}

void Person::show() const
{
    std::cout<<"ID:"<<id<<" Name:"<<name<<std::endl;
}

void Person::showName()
{
    std::cout<<name;
}

std::string Person::savePerson()
{
    return name;
}
