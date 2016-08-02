#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>

class Exception
{
public:
    Exception();
    ~Exception();

    const char* what() const noexcept;

};

#endif // EXCEPTION_H
