#pragma once
#include "AbstractResourceFactory.h"
#include "CGeneralResource.h"
class ResourceFactory :
    public AbstractResourceFactory
{
public:
    CGeneralResource* CreateResource() const override;
};

