#include "AResource.h"
#include "string"
#include <sstream>
#include <random>


unsigned int AResource::random_char() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 255);
	return dis(gen);
}

std::string AResource::GenerateUniqueResourceID(const unsigned int len) {
	std::stringstream ss;
	for (auto i = 0; i < len; i++) {
		const auto rc = random_char();
		std::stringstream hexstream;
		hexstream << std::hex << rc;
		auto hex = hexstream.str();
		ss << (hex.length() < 2 ? '0' + hex : hex);
	}
	return ss.str();
}

AResource::AResource()
{
	resourceID = GenerateUniqueResourceID(7);
	user_info = NULL;
}

bool AResource::operator==(AResource& rhs)
{	
	return this->resourceID == rhs.resourceID ? true : false;	
}

AResource::~AResource()
{
}

AUser* AResource::get_user_info()
{
	return user_info;
}

void AResource::set_user_info(AUser* user)
{
	user_info = user;
}

std::string AResource::getResourceID()
{
	return resourceID;
}
