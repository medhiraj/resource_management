#pragma once
#include "AUser.h"
#include "unordered_set"
#include "list"
class CGeneralUser :
    public AUser
{  
  unsigned int no_of_resource_available;
  std::list<std::string> list;
public:
  
  CGeneralUser(std::string name, unsigned int noOfResource);
  virtual bool ReserverResource(std::string resourceID) override;
  virtual bool FreeResource(std::string resourceId) override;
  virtual ~CGeneralUser();
  const std::list<std::string>& List() override;

};

