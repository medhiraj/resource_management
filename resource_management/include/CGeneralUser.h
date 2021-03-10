#pragma once
#include "AUser.h"
#include "unordered_set"
class CGeneralUser :
    public AUser
{

  std::unordered_set<std::string> allocatedResourceId;

public:
  
  CGeneralUser(std::string name, unsigned int noOfResource);
  virtual bool ReserverResource(std::string resourceID) override;
  virtual ~CGeneralUser();

};

