#pragma once
#include "iostream"
#include <mutex>
#include "AUser.h"
/// <summary>
/// 
/// </summary>
class AResource
{
	AUser* user_info;
	std::string resourceID;
	std::mutex g_mutex;
	unsigned int random_char();
	std::string GenerateUniqueResourceID(const unsigned int len);
	
	
public:
	AResource();
	virtual bool operator== (AResource& rhs);
	std::string getResourceID();
	AUser* get_user_info();
	void set_user_info(AUser*);
	virtual ~AResource();

};

