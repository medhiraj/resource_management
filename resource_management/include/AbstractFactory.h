#pragma once
#include "AResource.h"
#include "AUser.h"
class AbstractFactory {
public:
	virtual AResource* CreateResource() const = 0;
	virtual AUser* CreateUser() const = 0;
};