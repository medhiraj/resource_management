#pragma once
#include "UserFactory.h"
class CUserManager
{
private:
	std::unordered_set<AUser*> resourcePool;
public:
	AUser* CreateUser(const AbstractUserFactory& factory,std::string username, unsigned int noOfResource);
	bool AddUserToUserPool(AUser* userPtr);
};

