#pragma warning(disable:4996)

#include <iostream>
#include <fstream>
#include "hello.hh"


using namespace std;

class Time_impl :public virtual POA_Time {

public:

	virtual short get_gmt();

};

short Time_impl::get_gmt() {

	return 1234;

}

int mainIOR(int argc, char* argv[])
{
	CORBA::ORB_var orb;
	Time_impl* impl = NULL;

	try {

		//Initialize the ORB
		orb = CORBA::ORB_init(argc, argv);

		//Get a reference to the root POA
		CORBA::Object_var rootPOAObj

			= orb->resolve_initial_references("RootPOA");

		//Narrow it to the correct type
		PortableServer::POA_var rootPOA

			= PortableServer::POA::_narrow(rootPOAObj.in());

		//Create POA policies
		CORBA::PolicyList policies;
		policies.length(1);
		policies[0] =
			rootPOA->create_thread_policy(PortableServer::SINGLE_THREAD_MODEL);

		//Get the POA manager object
		PortableServer::POAManager_var manager = rootPOA->the_POAManager();

		//Create a new POA with specified policies
		PortableServer::POA_var myPOA = rootPOA->create_POA("myPOA", manager, policies);

		//Free policies
		CORBA::ULong len = policies.length();
		for (CORBA::ULong i = 0; i < len; i++)
			policies[i]->destroy();

		//Get a reference to the Naming Service root_context
		CORBA::Object_var rootContextObj =
			orb->resolve_initial_references("NameService");
		//Narrow to the correct type
		CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj.in());
		//CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj);

		//Create a reference to the servant
		impl = new Time_impl();
		//Activate object
		PortableServer::ObjectId_var myObjID =
			myPOA->activate_object(impl);

		//Get a CORBA reference with the POA through the servant
		CORBA::Object_var o = myPOA->servant_to_reference(impl);
		//The reference is converted to a character string
		_CORBA_String_var s = orb->object_to_string(o);
		cout << "The IOR of the object is: " << s.in() << endl;

		CosNaming::Name name;
		name.length(1);
		name[0].id = (const char *)"FirstTimeService";
		name[0].kind = (const char *)"";
		//Bind the Object into the name service
		nc->rebind(name, o);

		//Activate the POA
		manager->activate();
		cout << "The server is ready. Awaiting for incoming requests..." << endl;

		//Strat the ORB
		orb->run();

	}

	catch (const CORBA::Exception& e)
	{

		cerr << " exception " << e._name() << endl;

		return 1;

	}

	//Decrement reference count
	if (impl)
		impl->_remove_ref();

	//End CORBA
	if (!CORBA::is_nil(orb))
	{
		try
		{
			orb->destroy();
			cout << "Ending CORBA..." << endl;
		}
		catch (const CORBA::Exception& e)
		{
			cout << "orb->destroy() failed:" << e._name() << endl;
			return 1;
		}
	}

	return 0;

}

int main(int argc, char* argv[])
{
	CORBA::ORB_var orb;
	Time_impl* impl = NULL;
	try 
	{
		// Initialize the ORB  
		orb = CORBA::ORB_init(argc,argv);

		// Get a reference to the root POA 
		CORBA::Object_var rootPOAObj = orb->resolve_initial_references("RootPOA");

		// Narrow it to the correct type
		PortableServer::POA_var rootPOA = PortableServer::POA::_narrow(rootPOAObj.in());

		// Create POA policies   
		CORBA::PolicyList policies;
		policies.length(1);
		policies[0] = rootPOA->create_thread_policy(PortableServer::SINGLE_THREAD_MODEL);

		// Get the POA manager object
		PortableServer::POAManager_var manager = rootPOA->the_POAManager();

		// Create a new POA with specified policies 
		PortableServer::POA_var myPOA = rootPOA->create_POA("myPOA", manager, policies);

		// Free policies 
		CORBA::ULong len = policies.length();
		for (CORBA::ULong i = 0; i <len; i++)
		policies[i]->destroy();

		//Get a reference to the Naming Service root_context  
		CORBA::Object_var rootContextObj = orb->resolve_initial_references("NameService");

		// Narrow to the correct type  
		CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj.in());

		//CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj);    

		// Create a reference to the servant   
		impl = new Time_impl();

		// Activate object 
		PortableServer::ObjectId_var myObjID = myPOA->activate_object(impl);

		// Get a CORBA reference with the POA through the servant   
		CORBA::Object_var o = myPOA->servant_to_reference(impl);

		// The reference is converted to a character string   
		_CORBA_String_var s = orb->object_to_string(o);
		cout<<"The IOR of the object is:"<<s.in()<<endl;
		CosNaming::Name name;
		name.length(1);
		name[0].id =(const char*)"FirstTimeService";
		name[0].kind=(const char*)"";

		// Bind the Object into the name service 
		nc->rebind(name, o);

		//Activate the POA   
		manager->activate();

		cout<<"The server is ready. Awaiting for incoming requests..."<<endl;

		// Strat the ORB   
		orb->run();
	}
	catch (const CORBA::Exception& e)
	{
		cerr <<"exception "<<e._name()<<endl;
		return 1;
	}

	// Decrement reference count  
	if (impl)
	{
		impl->_remove_ref();
	}

	// End CORBA  
	if (!CORBA::is_nil(orb))
	{
		try
		{
			orb->destroy();
			cout<<"Ending CORBA..." << endl;
		}
		catch (const CORBA::Exception& e)
		{
			cout <<"orb->destroy() failed:" << e._name() << endl;
			return 1;
		}
	}
	return 0;
}