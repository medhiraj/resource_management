#include "../include/UserFactory.h"

AUser* UserFactory::CreateUser(std::string username, unsigned int noOfResource) const
{
	return new CGeneralUser(username,noOfResource);
}
