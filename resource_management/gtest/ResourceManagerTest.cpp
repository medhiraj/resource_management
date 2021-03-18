#include "gtest/gtest.h"
#include "CResourceManager.h"
#include "ResourceFactory.h"
#include "CCustomeException.h"


void InitilizeData(CResourceManager& resource_manager,const unsigned int no_of_resource,
                    std::string user_name[],const unsigned int no_of_user)
{


	ResourceFactory resource_factory;

	//Create some resource
	for (int i = 0; i < no_of_resource; i++)
	{
		resource_manager.CreateResource(resource_factory);
	}    
    
	for (int i = 0; i < no_of_user;i++)
	{
		resource_manager.AddUser(user_name[i], i);
    }    

}
TEST(ResourceManager, allocate) {
    const unsigned int NUMBER_OF_RESOURCE = 3;
    const unsigned int NUMBER_OF_USER = 4;

	CResourceManager resource_manager;

    std::string username[] = { "A0","A1","A2","A3","A4" };
    InitilizeData(resource_manager,NUMBER_OF_RESOURCE,username,NUMBER_OF_USER);
 
    std::string resourceId_A2[2];
    try
    {
       resourceId_A2[0] = resource_manager.Allocate(username[2]);
       EXPECT_NE(resourceId_A2[0],"");
       resourceId_A2[1] = resource_manager.Allocate(username[2]);
       EXPECT_NE(resourceId_A2[1],"");
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }

    //use case : max capacity has been reached for user
    try
    {
       std::string resoure_id_A2_1 = resource_manager.Allocate(username[2]);
    }
    catch(const CCustomeexception& e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_STREQ("Max Capacity 2 is recahed",e.what());        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }

    //use case : user is not present in  system.    
    try
    {
       std::string resoure_id_A2_1 = resource_manager.Allocate(username[4]);       
    }
    catch(const CCustomeexception& e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_STREQ("User not found",e.what());        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }

    //passing blank in user

    try
    {
       std::string resoure_id_A2_1 = resource_manager.Allocate("");       
    }
    catch(const CCustomeexception& e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_STREQ("User not found",e.what());        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }

    // usecase : No  free resource available in system.
    std::string resourceId_A1[1];
    try
    {
       resourceId_A1[0] = resource_manager.Allocate(username[1]);
    }
    catch(const CCustomeexception& e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_STREQ("Resource not available to allocate",e.what());        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }
}

TEST(ResourceManager, deallocate) {

    const unsigned int NUMBER_OF_RESOURCE = 3;
    const unsigned int NUMBER_OF_USER = 4;

	CResourceManager resource_manager;

    std::string username[] = { "A0","A1","A2","A3","A4" };
    InitilizeData(resource_manager,NUMBER_OF_RESOURCE,username,NUMBER_OF_USER);

    std::string resourceId_A2[2];
    try
    {
       resourceId_A2[0] = resource_manager.Allocate(username[2]);       
       resourceId_A2[1] = resource_manager.Allocate(username[2]);
       bool isSuccess;
       try
       {
          isSuccess   = resource_manager.Deallocate(resourceId_A2[0]);
          EXPECT_EQ(true,false);
       }
       catch(const CCustomeexception &e)
       {
            std::string msg ="No user is associated with resource id ";
            msg.append(resourceId_A2[0]);
            std::cout<<"Debug pt in catch "<<std::endl;
            //EXPECT_STREQ(msg.c_str(),e.what());
            //EXPECT_EQ(isSuccess,false);
            //EXPECT_EQ(true,Dalse);
       }
       catch(const std::exception& e)
       {
           std::cerr << e.what() << '\n';
       }
       
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }

    std::string resourceId_A1[1];
    /*try
    {
       resourceId_A1[0] = resource_manager.Allocate(username[1]);
    }
    catch(const CCustomeexception& e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_STREQ("Resource not available to allocate",e.what());        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }*/
}
