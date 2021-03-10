#include "../include/AUser.h"

AUser::AUser(std::string name, unsigned int numberOfResources)
{
	noOfResources = numberOfResources;
	userName.assign(name);
}
AUser::~AUser()
{
}
