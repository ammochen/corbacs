#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include "hello.hh"

using namespace std;

int mainXXX(int argc, char* argv[]) 
{

	try 
	{
		if (argc != 2) 
		{
			//throw 0;
		}

		CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

		// Read IOR from file ior.txt
		char bufferIOR[500];
		ifstream in("ior.txt");
		if (!in.is_open())
		{
			cout << "Error opening file"; exit(1);
		}
		while (!in.eof())
		{
			in.getline(bufferIOR, 500);
			cout << "Read IOR from file!" << endl;
		}

		CORBA::Object_var obj = orb->string_to_object(bufferIOR);

		if (CORBA::is_nil(obj)) 
		{
			cerr << "Nil Time Reference" << endl;
			throw 0;
		}

		Time_var tm = Time::_narrow(obj);

		if (CORBA::is_nil(tm))
		{
			cerr << "Nil Time Reference" << endl;
			throw 0;
		}

		cout << "Get from server, Time is:" << tm->get_gmt() << endl;

		system("pause");
	}
	catch (const CORBA::Exception&) 
	{
		cerr << "Got Exception!" << endl;
		return 1;
	}

	return 0;
}

int main(int argc, char* argv[])
{
	// Declare ORB
	CORBA::ORB_var orb;

	try
	{
		if (argc !=2)
		{
			//throw 0;
		}

		// Initialize the ORB
		orb = CORBA::ORB_init(argc, argv);

		// Get a reference to the Naming Service
		CORBA::Object_var rootContextObj = orb->resolve_initial_references("NameService");

		if (CORBA::is_nil(rootContextObj))
		{
			cerr << "Nil Time reference" << endl;
			throw 0;
		}

		CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj.in());

		CosNaming::Name name;
		name.length(1);
		name[0].id = (const char *)"FirstTimeService";
		name[0].kind = (const char *)"";

		// Invoke the root context to retrieve the object refernce
		CORBA::Object_var managerObj = nc->resolve(name);

		// Narrow the previous object to obtain the correct type
		::Time_var manager = ::Time::_narrow(managerObj.in());

		if (CORBA::is_nil(manager))
		{
			cerr << "Nil Time reference" << endl;
			throw 0;
		}

		cout << "OK, Let's have a look: " << manager->get_gmt() << endl;
	}
	catch (const CORBA::Exception& e)
	{
		cerr << "Client.main() Exception:" << e._name() << endl;
		return 1;
	}


}