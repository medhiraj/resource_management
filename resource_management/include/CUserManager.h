#pragma once
#include "UserFactory.h"
#include "unordered_map"

class CUserManager
{
private:
	std::unordered_map <std::string,AUser*> user_pool;
public:
	AUser* CreateUser(const AbstractUserFactory& factory,std::string username, unsigned int noOfResource);
	bool AddUserToUserPool(AUser* userPtr);
	bool isUserPresentInUserPool(std::string userName);
	AUser* getUser(std::string userName);
	
};

