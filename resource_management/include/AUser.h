#pragma once
#include "iostream"
#include "AResource.h"
class AUser
{
private : 
	unsigned int noOfResources;
	std::string userName;
public:
	AUser(std::string name,  unsigned  int numberOfResources);
	virtual bool ReserverResource(std::string resourceId) = 0;
	virtual ~AUser(); 
};