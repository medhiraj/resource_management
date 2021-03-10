#include "../include/CResourceManager.h"


AResource* CResourceManager::CreateResource(const AbstractResourceFactory& factory)
{
    auto resourcePtr =factory.CreateResource();	
	return resourcePtr;   
}

bool CResourceManager::AddResourceToResourcePool(AResource* resourse)
{
    bool isResourceAdded = false;
    if (resourse && resourcePool.find(resourse) == resourcePool.end())
    {
        resourcePool.insert(resourse);
        isResourceAdded = true;
    }
    return isResourceAdded;
}

