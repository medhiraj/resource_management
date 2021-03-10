


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

using namespace std;

int main(int argc, char** argv)
{
	const unsigned int NUMBER_OF_RESOURCE = 3;
	CResourceManager resource_manager;
	ResourceFactory resource_factory;
	//Create some resource
	for (int i = 0; i < NUMBER_OF_RESOURCE; i++)
	{
		resource_manager.CreateResource(resource_factory);
	}

	cout << "Resource Management" << endl;

	return 0;
}
