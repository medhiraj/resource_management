#include "../include/CGeneralUser.h"

CGeneralUser::CGeneralUser(std::string name, unsigned int noOfResource) : AUser(name,noOfResource)
{
}

bool CGeneralUser::ReserverResource(std::string resourceID)
{
	bool isResourceReserved = false;
	if (resourceID.compare("") != 0 && allocatedResourceId.find(resourceID) == allocatedResourceId.end())
	{
		allocatedResourceId.insert(resourceID);
	}
	return isResourceReserved;
}

CGeneralUser::~CGeneralUser()
{
}
