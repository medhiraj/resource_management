#pragma once
#include "iostream"
#include "exception"

class CCustomeexception : public std::exception
{
private : 
    std::string message;
    

public:
    CCustomeexception(std::string msg);
    virtual const char* what() const throw();

};



