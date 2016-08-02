#include "exception.h"

Exception::Exception()
{

}

Exception::~Exception()
{

}

const char* Exception::what() const noexcept
{
    return "No file found\n";
}

