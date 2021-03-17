#include "ResourceFactory.h"

CGeneralResource* ResourceFactory::CreateResource() const
{
	return new CGeneralResource();
}

