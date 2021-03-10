#pragma once
#include "AbstractUserFactory.h"
#include "CGeneralUser.h"
class UserFactory :
    public AbstractUserFactory
{
public:
    virtual AUser* CreateUser(std::string username, unsigned int noOfResource) const override;
};

