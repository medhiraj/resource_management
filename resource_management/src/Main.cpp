


/**
 * @file main.cppcc
 *
 * @This is the entry point for program ,It's test for resorce mangemner
 *
 *
 * @author Dhiraj Bhandare
 * Contact: dhiraj.bhandare@gmail.com
 *
 */
#include <iostream>
#include "..\include\CResourceManager.h"
#include "..\include\CUserManager.h"
#include "..\include\ResourceFactory.h"
#include "..\include\UserFactory.h"
#include "string"

using namespace std;

int main(int argc, char** argv)
{
	const unsigned int NUMBER_OF_RESOURCE = 3;
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
	for (int i = 0; i < 3; i++)
	{
		resource_manager.AddUser(username[i], i);
	}

	std::string resoure_id_A2_1 = resource_manager.Allocate(username[2]);
	std::string  resoure_id_A2_2 = resource_manager.Allocate(username[2]);

	std::list<std::string> list_resource_A2 = resource_manager.List(username[2]);
	list_resource_A2 = resource_manager.List(username[2]);

	std::string resoure_id_A1_1 = resource_manager.Allocate(username[1]);
	list_resource_A2 = resource_manager.List(username[1]);
	list_resource_A2 = resource_manager.List(username[0]);


	const std::list<user_resource_info>& list_resource = resource_manager.List();
	//list_resource = resource_manager.List();

	cout << "Resource Management" << endl;


	return 0;
}
