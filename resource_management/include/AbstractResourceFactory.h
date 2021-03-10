#pragma once
#include "AResource.h"

class AbstractResourceFactory {
public:
	virtual AResource* CreateResource() const = 0;
};