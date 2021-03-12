#include "../include/CCustomeException.h"


CCustomeexception::CCustomeexception(std::string msg)
{
    message.assign(msg);
}

const char* CCustomeexception::what() const throw()
{
    return message.c_str();
}