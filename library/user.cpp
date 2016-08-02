#include "user.h"

User::User(int a_id, std::string a_name) : Person(a_id, a_name)
{
}


void User::show() const
{
    Person::show();
}


std::string User::savePerson()
{
    return Person::savePerson()+"-";
}
