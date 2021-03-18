#include "gtest/gtest.h"
#include "CResourceManager.h"
#include "ResourceFactory.h"
#include "CCustomeException.h"
#include "list"

void InitilizeData(CResourceManager &resource_manager, const unsigned int no_of_resource,
                   std::string user_name[], const unsigned int no_of_user)
{

    ResourceFactory resource_factory;

    //Create some resource
    for (int i = 0; i < no_of_resource; i++)
    {
        resource_manager.CreateResource(resource_factory);
    }

    for (int i = 0; i < no_of_user; i++)
    {
        resource_manager.AddUser(user_name[i], i);
    }
}
TEST(ResourceManager, allocate)
{
    const unsigned int NUMBER_OF_RESOURCE = 3;
    const unsigned int NUMBER_OF_USER = 4;

    CResourceManager resource_manager;

    std::string username[] = {"A0", "A1", "A2", "A3", "A4"};
    InitilizeData(resource_manager, NUMBER_OF_RESOURCE, username, NUMBER_OF_USER);

    std::string resourceId_A2[2];
    try
    {
        resourceId_A2[0] = resource_manager.Allocate(username[2]);
        EXPECT_NE(resourceId_A2[0], "");
        resourceId_A2[1] = resource_manager.Allocate(username[2]);
        EXPECT_NE(resourceId_A2[1], "");
    }
    catch (const std::exception &e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }

    //use case : max capacity has been reached for user
    try
    {
        std::string resoure_id_A2_1 = resource_manager.Allocate(username[2]);
    }
    catch (const CCustomeexception &e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_STREQ("Max Capacity 2 is recahed", e.what());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }

    //use case : user is not present in  system.
    try
    {
        std::string resoure_id_A2_1 = resource_manager.Allocate(username[4]);
    }
    catch (const CCustomeexception &e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_STREQ("User not found", e.what());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }

    //passing blank in user

    try
    {
        std::string resoure_id_A2_1 = resource_manager.Allocate("");
    }
    catch (const CCustomeexception &e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_STREQ("User not found", e.what());
    }
    catch (const std::exception &e)
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
    catch (const CCustomeexception &e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_STREQ("Resource not available to allocate", e.what());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }
}

TEST(ResourceManager, deallocate)
{

    const unsigned int NUMBER_OF_RESOURCE = 3;
    const unsigned int NUMBER_OF_USER = 4;

    CResourceManager resource_manager;

    std::string username[] = {"A0", "A1", "A2", "A3", "A4"};
    InitilizeData(resource_manager, NUMBER_OF_RESOURCE, username, NUMBER_OF_USER);

    std::string resourceId_A2[2];
    try
    {
        resourceId_A2[0] = resource_manager.Allocate(username[2]);
        resourceId_A2[1] = resource_manager.Allocate(username[2]);
        bool isSuccess;
        try
        {
            isSuccess = resource_manager.Deallocate(resourceId_A2[0]);
            EXPECT_EQ(isSuccess, true);
            isSuccess = resource_manager.Deallocate(resourceId_A2[0]);
        }
        catch (const CCustomeexception &e)
        {
            std::string msg = "Associated  resource with " + resourceId_A2[0] + " is either free or incorrect";
            EXPECT_STREQ(msg.c_str(), e.what());
            isSuccess = resource_manager.Deallocate(resourceId_A2[1]);
            EXPECT_EQ(isSuccess, true);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    catch (const std::exception &e)
    {
        //std::cerr << e.what() << '\n';
        EXPECT_ANY_THROW(e.what());
    }
}

TEST(ResourceManager, list_Resources)
{

    const unsigned int NUMBER_OF_RESOURCE = 3;
    const unsigned int NUMBER_OF_USER = 4;

    CResourceManager resource_manager;

    std::string username[] = {"A0", "A1", "A2", "A3", "A4"};
    InitilizeData(resource_manager, NUMBER_OF_RESOURCE, username, NUMBER_OF_USER);

    std::string resourceId_A3[3];
    try
    {
        for (int i = 0; i < 3; i++)
        {
            resourceId_A3[i] = resource_manager.Allocate(username[3]);
        }
        std::list<std::string> listResources = resource_manager.List(username[3]);

        EXPECT_EQ(3, listResources.size());
        std::list<std::string>::iterator itr = listResources.begin();

        for (int i = 0; i < 3 && itr == listResources.end(); i++, itr++)
        {
            EXPECT_STREQ(resourceId_A3[i].c_str(), (*itr).c_str());
        }
        bool isSuccess = resource_manager.Deallocate(resourceId_A3[2]);
        EXPECT_EQ(isSuccess, true);
        listResources = resource_manager.List(username[3]);
        EXPECT_EQ(2, listResources.size());

        itr = listResources.begin();

        for (int i = 0; i < 2 && itr == listResources.end(); i++, itr++)
        {
            EXPECT_STREQ(resourceId_A3[i].c_str(), (*itr).c_str());
        }

        listResources = resource_manager.List(username[0]);
        EXPECT_EQ(0, listResources.size());
        try
        {
            listResources = resource_manager.List("");
        }
        catch (const std::exception &e)
        {
            EXPECT_STREQ("User not found", e.what());
            
        }
    }
    catch (const CCustomeexception &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

TEST(ResourceManager, list_all_Resources)
{

    const unsigned int NUMBER_OF_RESOURCE = 5;
    const unsigned int NUMBER_OF_USER = 4;

    CResourceManager resource_manager;

    std::string username[] = {"A0", "A1", "A2", "A3", "A4"};
    InitilizeData(resource_manager, NUMBER_OF_RESOURCE, username, NUMBER_OF_USER);

    std::string resourceId_user[5][4];
    try
    {
        std::list<user_resource_info> listUserResourceInfo = resource_manager.List();
        EXPECT_EQ(0,listUserResourceInfo.size());
        for(int i=1 ;i<4 ;i++)
        {
            resourceId_user[i][0] = resource_manager.Allocate(username[i]);
        }
        listUserResourceInfo = resource_manager.List();
        EXPECT_EQ(3,listUserResourceInfo.size());
        std::list<user_resource_info>::iterator itr = listUserResourceInfo.begin();
        for(int i=1;i<4 && itr!=listUserResourceInfo.end();itr++,i++)
        {            
            EXPECT_STREQ((*itr).getUserName().c_str(),username[i].c_str());
            EXPECT_STREQ((*itr).getResource_ID().c_str(),resourceId_user[i][0].c_str());
        }

        resourceId_user[3][1] = resource_manager.Allocate(username[3]);

        listUserResourceInfo = resource_manager.List();
        EXPECT_EQ(4,listUserResourceInfo.size());
        itr = listUserResourceInfo.begin();
        for(int i=1;i<4 && itr!=listUserResourceInfo.end();itr++,i++)
        {            
            EXPECT_STREQ((*itr).getUserName().c_str(),username[i].c_str());
            EXPECT_STREQ((*itr).getResource_ID().c_str(),resourceId_user[i][0].c_str());
            if(i==3)
            {
                itr++;
                EXPECT_STREQ((*itr).getUserName().c_str(),username[i].c_str());
                EXPECT_STREQ((*itr).getResource_ID().c_str(),resourceId_user[i][1].c_str());
            }
        }
        
    }
    catch(const CCustomeexception& e)
    {

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
