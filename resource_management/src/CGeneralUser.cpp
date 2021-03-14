#include "../include/CGeneralUser.h"
#include "../include/CCustomeException.h"
#include "string"
#include "algorithm"
CGeneralUser::CGeneralUser(std::string name, unsigned int noOfResource) : AUser(name,noOfResource)
{
	no_of_resource_available = noOfResource;
}

bool CGeneralUser::ReserverResource(std::string resourceID)
{
	bool isResourceReserved = false;

	if (resourceID.compare(""))
	{
		std::unordered_set<std::string>& allocatedResourceId = getallocatedResourceIdSet();
		if (allocatedResourceId.find(resourceID) == allocatedResourceId.end())
		{
			if (no_of_resource_available)
			{
				allocatedResourceId.insert(resourceID);
				no_of_resource_available--;
				isResourceReserved = true;
			}
			else
			{
				throw CCustomeexception("Max Capacity " + std::to_string(getNoOfResource()) + " is recahed");
			}
		}
		else
		{
			throw CCustomeexception("Resource is already allocated to user");
		}
	}
	else
	{
		throw CCustomeexception("Resource id is blank");
	}
	return isResourceReserved;
}

bool CGeneralUser::FreeResource(std::string resourceID)
{
	bool isResourcefreed = false;
	if (resourceID.compare(""))
	{
		std::unordered_set<std::string>& allocatedResourceId = getallocatedResourceIdSet();
		auto it = allocatedResourceId.find(resourceID);
		if (it != allocatedResourceId.end())
		{
			allocatedResourceId.erase(it);
			no_of_resource_available++;
			isResourcefreed = true;
		}
		else
		{
			throw CCustomeexception("Resource " + resourceID +"is not associted  to user");
		}
	}
	else
	{
		throw CCustomeexception("Resource id is blank");
	}
	return isResourcefreed;
}

CGeneralUser::~CGeneralUser()
{
}

const std::list<std::string>& CGeneralUser::List()
{

	if (list.size() > 0)
		list.clear();
	std::unordered_set<std::string>& allocatedResourceId = getallocatedResourceIdSet();
	std::copy(allocatedResourceId.begin(), allocatedResourceId.end(), std::back_inserter(list));

	return list;
}
