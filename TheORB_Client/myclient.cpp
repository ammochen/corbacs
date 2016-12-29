#pragma warning(disable:4996)
#include <iostream>

#include "hello.hh"

using namespace std;

int main(int argc, char* argv[]) 
{

	try 
	{
		if (argc != 2) 
		{
			throw 0;
		}

		CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);
		CORBA::Object_var obj = orb->string_to_object(argv[1]);

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
	}
	catch (const CORBA::Exception&) 
	{
		cerr << "Got Exception!" << endl;
		return 1;
	}

	return 0;
}