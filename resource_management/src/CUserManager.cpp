#include "..\include\CUserManager.h"

AUser* CUserManager::CreateUser(const AbstractUserFactory& factory, std::string username, unsigned int noOfResource)
{
	auto resourcePtr = factory.CreateUser(username,noOfResource);
	return resourcePtr;
}

bool CUserManager::AddUserToUserPool(AUser* user)
{
    bool isUserAdded = false;
    if (user && resourcePool.find(user) == resourcePool.end()) // Not allowing duplicate user with username
    {
        resourcePool.insert(user);
        isUserAdded = true;
    }
    return isUserAdded;
}
