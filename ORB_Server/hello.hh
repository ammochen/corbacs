// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.
#ifndef __hello_hh__
#define __hello_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef  USE_stub_in_nt_dll
# define USE_stub_in_nt_dll_NOT_DEFINED_hello
#endif
#ifndef  USE_core_stub_in_nt_dll
# define USE_core_stub_in_nt_dll_NOT_DEFINED_hello
#endif
#ifndef  USE_dyn_stub_in_nt_dll
# define USE_dyn_stub_in_nt_dll_NOT_DEFINED_hello
#endif






#ifdef USE_stub_in_nt_dll
# ifndef USE_core_stub_in_nt_dll
#  define USE_core_stub_in_nt_dll
# endif
# ifndef USE_dyn_stub_in_nt_dll
#  define USE_dyn_stub_in_nt_dll
# endif
#endif

#ifdef _core_attr
# error "A local CPP macro _core_attr has already been defined."
#else
# ifdef  USE_core_stub_in_nt_dll
#  define _core_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _core_attr
# endif
#endif

#ifdef _dyn_attr
# error "A local CPP macro _dyn_attr has already been defined."
#else
# ifdef  USE_dyn_stub_in_nt_dll
#  define _dyn_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _dyn_attr
# endif
#endif





#ifndef __Time__
#define __Time__

class Time;
class _objref_Time;
class _impl_Time;

typedef _objref_Time* Time_ptr;
typedef Time_ptr TimeRef;

class Time_Helper {
public:
	typedef Time_ptr _ptr_type;

	static _ptr_type _nil();
	static _CORBA_Boolean is_nil(_ptr_type);
	static void release(_ptr_type);
	static void duplicate(_ptr_type);
	static void marshalObjRef(_ptr_type, cdrStream&);
	static _ptr_type unmarshalObjRef(cdrStream&);
};

typedef _CORBA_ObjRef_Var<_objref_Time, Time_Helper> Time_var;
typedef _CORBA_ObjRef_OUT_arg<_objref_Time, Time_Helper > Time_out;

#endif

// interface Time
class Time {
public:
	// Declarations for this interface type.
	typedef Time_ptr _ptr_type;
	typedef Time_var _var_type;

	static _ptr_type _duplicate(_ptr_type);
	static _ptr_type _narrow(::CORBA::Object_ptr);
	static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);

	static _ptr_type _nil();

	static inline void _marshalObjRef(_ptr_type, cdrStream&);

	static inline _ptr_type _unmarshalObjRef(cdrStream& s) {
		omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId, s);
		if (o)
			return (_ptr_type)o->_ptrToObjRef(_PD_repoId);
		else
			return _nil();
	}

	static _core_attr const char* _PD_repoId;

	// Other IDL defined within this scope.

};

class _objref_Time :
	public virtual ::CORBA::Object,
	public virtual omniObjRef
{
public:
	::CORBA::Short get_gmt();

	inline _objref_Time() { _PR_setobj(0); }  // nil
	_objref_Time(omniIOR*, omniIdentity*);

protected:
	virtual ~_objref_Time();


private:
	virtual void* _ptrToObjRef(const char*);

	_objref_Time(const _objref_Time&);
	_objref_Time& operator = (const _objref_Time&);
	// not implemented

	friend class Time;
};

class _pof_Time : public _OMNI_NS(proxyObjectFactory) {
public:
	inline _pof_Time() : _OMNI_NS(proxyObjectFactory)(Time::_PD_repoId) {}
	virtual ~_pof_Time();

	virtual omniObjRef* newObjRef(omniIOR*, omniIdentity*);
	virtual _CORBA_Boolean is_a(const char*) const;
};

class _impl_Time :
	public virtual omniServant
{
public:
	virtual ~_impl_Time();

	virtual ::CORBA::Short get_gmt() = 0;

public:  // Really protected, workaround for xlC
	virtual _CORBA_Boolean _dispatch(omniCallHandle&);

private:
	virtual void* _ptrToInterface(const char*);
	virtual const char* _mostDerivedRepoId();

};




class POA_Time :
	public virtual _impl_Time,
	public virtual ::PortableServer::ServantBase
{
public:
	virtual ~POA_Time();

	inline ::Time_ptr _this() {
		return (::Time_ptr) _do_this(::Time::_PD_repoId);
	}
};







#undef _core_attr
#undef _dyn_attr



inline void
Time::_marshalObjRef(::Time_ptr obj, cdrStream& s) {
	omniObjRef::_marshal(obj->_PR_getobj(), s);
}




#ifdef   USE_stub_in_nt_dll_NOT_DEFINED_hello
# undef  USE_stub_in_nt_dll
# undef  USE_stub_in_nt_dll_NOT_DEFINED_hello
#endif
#ifdef   USE_core_stub_in_nt_dll_NOT_DEFINED_hello
# undef  USE_core_stub_in_nt_dll
# undef  USE_core_stub_in_nt_dll_NOT_DEFINED_hello
#endif
#ifdef   USE_dyn_stub_in_nt_dll_NOT_DEFINED_hello
# undef  USE_dyn_stub_in_nt_dll
# undef  USE_dyn_stub_in_nt_dll_NOT_DEFINED_hello
#endif

#endif  // __hello_hh__
