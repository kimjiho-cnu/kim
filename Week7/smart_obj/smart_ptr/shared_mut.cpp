//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
	 _mgr = new mgr(_obj);	
	 increase();
}


shared_mut::~shared_mut()
{
    release();
}

Object* shared_mut::operator->()
{
	return this->_mgr->ptr;
}

void shared_mut::increase()
{	
	this->_mgr->count++;
}

Object* shared_mut::get() const
{	if(_mgr == nullptr){
		return nullptr;
	}else{

	return _mgr->ptr;
}
}
void shared_mut::release() {

	if(this->_mgr->count != 0){
		this->_mgr->count--;
		this->_mgr = new mgr();
	}else{
		delete this->_mgr;
		this->_mgr = new mgr();
}
		this->_mgr = new mgr();
	
}

int shared_mut::count(){
	return this->_mgr->count;
}

shared_mut shared_mut::operator+(const shared_mut &shared){
	int nv = this->_mgr->ptr->get() + shared._mgr->ptr->get();
	shared_mut r(new Object(nv));
	return r;
	
}

shared_mut shared_mut::operator-(const shared_mut &shared){
	int nv = this->_mgr->ptr->get() - shared._mgr->ptr->get();
	shared_mut r(new Object(nv));
	return r;
}

shared_mut shared_mut::operator*(const shared_mut &shared){
	int nv = this->_mgr->ptr->get() * shared._mgr->ptr->get();
	shared_mut r(new Object(nv));
	return r;
}

shared_mut shared_mut::operator/(const shared_mut &shared){
	int nv =this-> _mgr->ptr->get() / shared._mgr->ptr->get();
	shared_mut r(new Object(nv));
	return r;
}
shared_mut &shared_mut::operator=(const shared_mut &r){
	this->_mgr = r._mgr;
	
	return *this;

}
}
 // end of namespace ptr
