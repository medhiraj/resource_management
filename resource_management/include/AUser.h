#pragma once
#include "iostream"
#include "unordered_set"
#include "list"


class AUser
{
private : 
	unsigned int noOfResources;
	std::string userName;
	std::unordered_set<std::string> allocatedResourceId;
public:
	AUser(std::string name,  unsigned  int numberOfResources);
	//
	virtual bool ReserverResource(std::string resourceId) = 0;
	virtual bool FreeResource(std::string resourceId) = 0;
	virtual const std::list<std::string>& List() = 0;
	//virtual bool operator== (AUser& rhs);
	std::unordered_set<std::string>& getallocatedResourceIdSet();
	virtual ~AUser(); 
	virtual std::string getUserName();
	virtual unsigned int getNoOfResource();
	//virtual bool operator()(AUser& rhs) const;
};

