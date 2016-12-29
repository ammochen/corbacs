// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.
#pragma warning(disable:4996)
#include "hello.hh"
#include <omniORB4/IOP_S.h>
#include <omniORB4/IOP_C.h>
#include <omniORB4/callDescriptor.h>
#include <omniORB4/callHandle.h>
#include <omniORB4/objTracker.h>


OMNI_USING_NAMESPACE(omni)

static const char* _0RL_library_version = omniORB_4_1;



Time_ptr Time_Helper::_nil() {
	return ::Time::_nil();
}

::CORBA::Boolean Time_Helper::is_nil(::Time_ptr p) {
	return ::CORBA::is_nil(p);

}

void Time_Helper::release(::Time_ptr p) {
	::CORBA::release(p);
}

void Time_Helper::marshalObjRef(::Time_ptr obj, cdrStream& s) {
	::Time::_marshalObjRef(obj, s);
}

Time_ptr Time_Helper::unmarshalObjRef(cdrStream& s) {
	return ::Time::_unmarshalObjRef(s);
}

void Time_Helper::duplicate(::Time_ptr obj) {
	if (obj && !obj->_NP_is_nil())  omni::duplicateObjRef(obj);
}

Time_ptr
Time::_duplicate(::Time_ptr obj)
{
	if (obj && !obj->_NP_is_nil())  omni::duplicateObjRef(obj);
	return obj;
}

Time_ptr
Time::_narrow(::CORBA::Object_ptr obj)
{
	if (!obj || obj->_NP_is_nil() || obj->_NP_is_pseudo()) return _nil();
	_ptr_type e = (_ptr_type)obj->_PR_getobj()->_realNarrow(_PD_repoId);
	return e ? e : _nil();
}


Time_ptr
Time::_unchecked_narrow(::CORBA::Object_ptr obj)
{
	if (!obj || obj->_NP_is_nil() || obj->_NP_is_pseudo()) return _nil();
	_ptr_type e = (_ptr_type)obj->_PR_getobj()->_uncheckedNarrow(_PD_repoId);
	return e ? e : _nil();
}

Time_ptr
Time::_nil()
{
#ifdef OMNI_UNLOADABLE_STUBS
	static _objref_Time _the_nil_obj;
	return &_the_nil_obj;
#else
	static _objref_Time* _the_nil_ptr = 0;
	if (!_the_nil_ptr) {
		omni::nilRefLock().lock();
		if (!_the_nil_ptr) {
			_the_nil_ptr = new _objref_Time;
			registerNilCorbaObject(_the_nil_ptr);
		}
		omni::nilRefLock().unlock();
	}
	return _the_nil_ptr;
#endif
}

const char* Time::_PD_repoId = "IDL:Time:1.0";


_objref_Time::~_objref_Time() {

}


_objref_Time::_objref_Time(omniIOR* ior, omniIdentity* id) :
	omniObjRef(::Time::_PD_repoId, ior, id, 1)


{
	_PR_setobj(this);
}

void*
_objref_Time::_ptrToObjRef(const char* id)
{
	if (id == ::Time::_PD_repoId)
		return (::Time_ptr) this;

	if (id == ::CORBA::Object::_PD_repoId)
		return (::CORBA::Object_ptr) this;

	if (omni::strMatch(id, ::Time::_PD_repoId))
		return (::Time_ptr) this;

	if (omni::strMatch(id, ::CORBA::Object::_PD_repoId))
		return (::CORBA::Object_ptr) this;

	return 0;
}

// Proxy call descriptor class. Mangled signature:
//  _cshort
class _0RL_cd_7A79FCDEB9F446D5_00000000
	: public omniCallDescriptor
{
public:
	inline _0RL_cd_7A79FCDEB9F446D5_00000000(LocalCallFn lcfn, const char* op_, size_t oplen, _CORBA_Boolean upcall = 0) :
		omniCallDescriptor(lcfn, op_, oplen, 0, _user_exns, 0, upcall)
	{

	}


	void unmarshalReturnedValues(cdrStream&);
	void marshalReturnedValues(cdrStream&);


	static const char* const _user_exns[];

	::CORBA::Short result;
};

void _0RL_cd_7A79FCDEB9F446D5_00000000::marshalReturnedValues(cdrStream& _n)
{
	result >>= _n;

}

void _0RL_cd_7A79FCDEB9F446D5_00000000::unmarshalReturnedValues(cdrStream& _n)
{
	(::CORBA::Short&)result <<= _n;

}

const char* const _0RL_cd_7A79FCDEB9F446D5_00000000::_user_exns[] = {
	0
};

// Local call call-back function.
static void
_0RL_lcfn_7A79FCDEB9F446D5_10000000(omniCallDescriptor* cd, omniServant* svnt)
{
	_0RL_cd_7A79FCDEB9F446D5_00000000* tcd = (_0RL_cd_7A79FCDEB9F446D5_00000000*)cd;
	_impl_Time* impl = (_impl_Time*)svnt->_ptrToInterface(Time::_PD_repoId);
	tcd->result = impl->get_gmt();


}

::CORBA::Short _objref_Time::get_gmt()
{
	_0RL_cd_7A79FCDEB9F446D5_00000000 _call_desc(_0RL_lcfn_7A79FCDEB9F446D5_10000000, "get_gmt", 8);


	_invoke(_call_desc);
	return _call_desc.result;


}
_pof_Time::~_pof_Time() {}


omniObjRef*
_pof_Time::newObjRef(omniIOR* ior, omniIdentity* id)
{
	return new ::_objref_Time(ior, id);
}


::CORBA::Boolean
_pof_Time::is_a(const char* id) const
{
	if (omni::ptrStrMatch(id, ::Time::_PD_repoId))
		return 1;

	return 0;
}

const _pof_Time _the_pof_Time;

_impl_Time::~_impl_Time() {}


::CORBA::Boolean
_impl_Time::_dispatch(omniCallHandle& _handle)
{
	const char* op = _handle.operation_name();

	if (omni::strMatch(op, "get_gmt")) {

		_0RL_cd_7A79FCDEB9F446D5_00000000 _call_desc(_0RL_lcfn_7A79FCDEB9F446D5_10000000, "get_gmt", 8, 1);

		_handle.upcall(this, _call_desc);
		return 1;
	}


	return 0;
}

void*
_impl_Time::_ptrToInterface(const char* id)
{
	if (id == ::Time::_PD_repoId)
		return (::_impl_Time*) this;

	if (id == ::CORBA::Object::_PD_repoId)
		return (void*)1;

	if (omni::strMatch(id, ::Time::_PD_repoId))
		return (::_impl_Time*) this;

	if (omni::strMatch(id, ::CORBA::Object::_PD_repoId))
		return (void*)1;
	return 0;
}

const char*
_impl_Time::_mostDerivedRepoId()
{
	return ::Time::_PD_repoId;
}

POA_Time::~POA_Time() {}

