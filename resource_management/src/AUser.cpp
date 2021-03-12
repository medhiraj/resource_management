#include "../include/AUser.h"

AUser::AUser(std::string name, unsigned int numberOfResources)
{
	noOfResources = numberOfResources;
	userName.assign(name);
}
std::unordered_set<std::string>& AUser::getallocatedResourceIdSet()
{
	return allocatedResourceId;
}
//bool AUser::operator==(AUser& rhs)
//{
//	return this->userName.compare(rhs.userName) ? true : false;
//}
AUser::~AUser()
{
}

std::string AUser::getUserName()
{
	return userName;
}

unsigned int AUser::getNoOfResource()
{
	return noOfResources;
}



