#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include "hello.hh"

using namespace std;

int main(int argc, char* argv[]) 
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