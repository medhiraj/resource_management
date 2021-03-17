#include "gtest/gtest.h"
#include "CResourceManager.h"
#include "ResourceFactory.h"
#include "CCustomeException.h"

TEST(ResourceManager, allocate) {
    const unsigned int NUMBER_OF_RESOURCE = 3;
    const unsigned int NUMBER_OF_USER = 4;

	CResourceManager resource_manager;
	ResourceFactory resource_factory;
	//CUserManager user_manager;
	//UserFactory user_factory;
	//Create some resource
	for (int i = 0; i < NUMBER_OF_RESOURCE; i++)
	{
		resource_manager.CreateResource(resource_factory);
	}

    
    std::string username[] = { "A1","A2","A3","A4" };
	for (int i = 0; i < NUMBER_OF_USER;i++)
	{
		resource_manager.AddUser(username[i], i);
    }    

    try
    {
       std::string resoure_id_A2_1 = resource_manager.Allocate(username[2]);
       EXPECT_NE(resoure_id_A2_1,"");
       std::string resoure_id_A2_2 = resource_manager.Allocate(username[2]);
       EXPECT_NE(resoure_id_A2_2,"");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }

    try
    {
       std::string resoure_id_A2_1 = resource_manager.Allocate(username[2]);
    }
    catch(const CCustomeexception& e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_EQ("Max Capacity 2  is recahed",e.what());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }
}