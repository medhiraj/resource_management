#pragma once
#include "iostream"
#include <mutex>
/// <summary>
/// 
/// </summary>
class AResource
{
	std::string resourceID;
	std::mutex g_mutex;
	std::string GenerateUniqueResourceID();
	double GetElappsedSceond();
public:
	AResource();
	virtual ~AResource();

};

