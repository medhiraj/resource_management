#pragma once
#include "AbstractFactory.h"
#include "CGeneralResource.h"
class ResourceFactory :
    public AbstractFactory
{
public:
    CGeneralResource* CreateResource() const override;
};

