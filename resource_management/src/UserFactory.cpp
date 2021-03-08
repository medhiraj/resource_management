#include "..\include\UserFactory.h"

CGeneralUser* UserFactory::CreateUser() const
{
	return new CGeneralUser();
}
