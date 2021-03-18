#pragma once
#include "AResource.h"
#include "unordered_map"
#include "AbstractResourceFactory.h"
#include "CUserManager.h"
#include "list"

class user_resource_info
{
	std::string user_name;
	std::string resource_id;
public:
	user_resource_info(std::string userName, std::string resourceId);
	std::string getUserName();
	std::string getResource_ID();
};

class CResourceManager
{
	
private :
	std::unordered_map<std::string,AResource*> resourcePool;
	std::unordered_map<std::string, AResource*> reserved_resourcePool;
	CUserManager user_manager;
	std::list<std::string> list_resource_id;
	std::list<user_resource_info> user_resource_info_list;
public:
	AResource* CreateResource(const AbstractResourceFactory& factory);
	bool AddResourceToResourcePool(AResource* resourcePtr);
	std::string Allocate(std::string user_name);	
	bool Deallocate(std::string resource_id);
	bool AddUser(std::string user_name, unsigned int noOfResource);
	const std::list<std::string>& List(std::string user_name);
	const std::list<user_resource_info>& List();
};

