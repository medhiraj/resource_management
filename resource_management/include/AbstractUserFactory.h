#pragma once
#include "AUser.h"
class AbstractUserFactory
{
public:
	virtual AUser* CreateUser(std::string username,unsigned int noOfResource) const = 0;
};

