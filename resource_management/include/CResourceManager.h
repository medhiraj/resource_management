#pragma once
#include "AResource.h"
#include "unordered_set"
#include "AbstractResourceFactory.h"
class CResourceManager
{
	
private :
	std::unordered_set<AResource*> resourcePool;
public:
	AResource* CreateResource(const AbstractResourceFactory& factory);
	bool AddResourceToResourcePool(AResource* resourcePtr);
	//std::string Allocate(std::string user_name);
	//bool Deallocate(std::string resource_id)

};

