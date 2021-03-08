#pragma once
#include "AbstractFactory.h"
#include "CGeneralUser.h"
class UserFactory :
    public AbstractFactory
{

    CGeneralUser* CreateUser() const override;
};

