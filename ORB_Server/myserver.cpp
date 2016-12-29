#pragma warning(disable:4996)

#include <iostream>
#include "hello.hh"

using namespace std;
class Time_impl :public virtual POA_Time 
{
public:
	virtual short get_gmt();

};

short Time_impl::get_gmt() 
{
	return 33445;
}

int main(int argc, char* argv[]) 
{
	try 
	{
		CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);
		CORBA::Object_var obj = orb->resolve_initial_references("RootPOA");

		PortableServer::POA_var poa = PortableServer::POA::_narrow(obj);
		PortableServer::POAManager_var mgr = poa->the_POAManager();

		mgr->activate();
		Time_impl time_servant;
		Time_var tm = time_servant._this();
		CORBA::String_var str = orb->object_to_string(tm);
		cout << str << endl;
		orb->run();
	}
	catch (const CORBA::Exception&) 
	{
		cerr << "exception" << endl;
		return 1;
	}
	return 0;
}