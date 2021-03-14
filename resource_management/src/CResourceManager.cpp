#include "../include/CResourceManager.h"
#include "../include/CCustomeException.h"


AResource* CResourceManager::CreateResource(const AbstractResourceFactory& factory)
{
    auto resourcePtr =factory.CreateResource();	
    if (resourcePtr)
    {
        AddResourceToResourcePool(resourcePtr);
    }
	return resourcePtr;   
}

bool CResourceManager::AddResourceToResourcePool(AResource* resourse)
{
    bool isResourceAdded = false;
    if (resourse && resourcePool.find(resourse->getResourceID()) == resourcePool.end())
    {
        resourcePool.insert(std::make_pair(resourse->getResourceID(), resourse));
        isResourceAdded = true;
    }
    return isResourceAdded;
}

std::string CResourceManager::Allocate(std::string user_name)
{    
    auto it = resourcePool.begin();
    
    //Check if any free resource
    if (it != resourcePool.end() && resourcePool.size() > 0)
    {
        // Check User is valid
        
        if (user_manager.isUserPresentInUserPool(user_name))
        {
            AUser* user = user_manager.getUser(user_name);
            if (user)
            {
                if (user->ReserverResource(it->first))
                {
                    it->second->set_user_info(user);
                    auto new_it = reserved_resourcePool.insert(std::make_pair(it->first, it->second));
                    resourcePool.erase(it);
                    return new_it.first->first;
                }
                else
                {
                    throw CCustomeexception("Unable allocate resource to " + user_name);
                }
            }
            else
            {
                throw CCustomeexception("User not found");

            }
        }
        else
        {            
            throw CCustomeexception("User not found");
        }       
    }
    else
    {
        throw CCustomeexception("Resource not available to allocate");
    }

    return std::string();
}

bool CResourceManager::Deallocate(std::string resource_id)
{
    bool isResourceFree = false;
    auto it = reserved_resourcePool.find(resource_id);
    if (it != reserved_resourcePool.end())
    {
        AResource* resource = it->second;
        AUser* user = resource->get_user_info();
        if (user)
        {
            if (user->FreeResource(resource_id))
            {                
                it->second->set_user_info(nullptr);
                auto new_it = resourcePool.insert(std::make_pair(it->first, it->second));
                reserved_resourcePool.erase(it);
                isResourceFree = true;
            }
            else
            {
                throw CCustomeexception("Unable to free resource id " + resource_id + " associated with user " + user->getUserName());
            }

        }
        {
            throw CCustomeexception("No user is associated with resource id " + resource_id);
        }
        
    }
    else
    {
        throw CCustomeexception("Associated  resource with " + resource_id + " is either free or incorrect");

    }
    return isResourceFree;
}

bool CResourceManager::AddUser(std::string user_name, unsigned int noOfResource)
{
    UserFactory user_factory;
    AUser* user = user_manager.CreateUser(user_factory, user_name, noOfResource);
    if (user)
        return true;
    else
        return false;
}

const std::list<std::string>& CResourceManager::List(std::string user_name)
{
    
    if (user_manager.isUserPresentInUserPool(user_name))
    {
        AUser* user = user_manager.getUser(user_name);
        if (user)
        {
            list_resource_id = user->List();
        }
        else
        {
            throw CCustomeexception("User not found");
        }
    }
    else
    {
        throw CCustomeexception("User not found");
    }
    return list_resource_id;
}

const std::list<user_resource_info>& CResourceManager::List()
{    
    if (user_resource_info_list.size() > 0)
        user_resource_info_list.clear();
    for (auto it = reserved_resourcePool.begin(); it != reserved_resourcePool.end(); ++it)
    {
        user_resource_info_list.push_front(user_resource_info(it->second->get_user_info()->getUserName(), it->first));
    }
    return user_resource_info_list;
}

user_resource_info::user_resource_info(std::string userName, std::string resourceId)
{
    user_name.assign(userName);
    resource_id.assign(resourceId);
}
