#include "..\include\CUserManager.h"

AUser* CUserManager::CreateUser(const AbstractUserFactory& factory, std::string username, unsigned int noOfResource)
{
	auto user_ptr = factory.CreateUser(username,noOfResource);
    if (user_ptr)
    {
        AddUserToUserPool(user_ptr);     
    }
	return user_ptr;
}

bool CUserManager::AddUserToUserPool(AUser* user)
{
    bool isUserAdded = false;
    if (user && user_pool.find(user->getUserName()) == user_pool.end()) // Not allowing duplicate user with username
    {
        user_pool.insert(std::make_pair(user->getUserName(),user));
        isUserAdded = true;
    }
    return isUserAdded;
}

bool CUserManager::isUserPresentInUserPool(std::string userName)
{
    return user_pool.find(userName) != user_pool.end() ? true : false;
}

AUser* CUserManager::getUser(std::string userName)
{
    auto it = user_pool.find(userName);
    if (it != user_pool.end())
        return it->second;
    return nullptr;
}
