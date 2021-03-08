#include "..\include\AResource.h"
#include "time.h"
#include "string"

std::string AResource::GenerateUniqueResourceID()
{
	std::string strResourceID;
	g_mutex.lock();
	auto seconds = GetElappsedSceond();
	g_mutex.unlock();
	strResourceID.append("rd").append(std::to_string(seconds));
	return strResourceID;
}

double AResource::GetElappsedSceond()
{

	time_t timer;
	struct tm y2k = { 0 };
	double seconds;

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);  /* get current time; same as: timer = time(NULL)  */

	seconds = difftime(timer, mktime(&y2k));
	return seconds;
}



AResource::AResource()
{
	resourceID = GenerateUniqueResourceID();
}

AResource::~AResource()
{
}
