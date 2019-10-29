//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

void unique_immut::release() {
	if(_mgr->ptr != nullptr){
		this->_mgr->~mgr();

}	this->_mgr->count++;

}

Object* unique_immut::get() const {
	if(_mgr->ptr == nullptr){
		return nullptr;
	}else{
		return _mgr->ptr;
}
}

Object* unique_immut::operator->() {
	return _mgr->ptr;
}

unique_immut::~unique_immut() {
    release();
}



unique_immut unique_immut::operator+(unique_immut& unique) {
	int nv = this->_mgr->ptr->get() + unique._mgr->ptr->get();
	this->release();
	unique.release();
	return unique_immut(new Object(nv));
}
unique_immut unique_immut::operator-(unique_immut& unique) {
          int nv = this->_mgr->ptr->get() - unique._mgr->ptr->get();
          this->release();
          unique.release();
          return unique_immut(new Object(nv));
  }
unique_immut unique_immut::operator*(unique_immut& unique) {
          int nv = this->_mgr->ptr->get() * unique._mgr->ptr->get();
          this->release();
          unique.release();
          return unique_immut(new Object(nv));
  }
unique_immut unique_immut::operator/(unique_immut& unique) {
          int nv = this->_mgr->ptr->get() / unique._mgr->ptr->get();
          this->release();
          unique.release();
          return unique_immut(new Object(nv));
  }
unique_immut &unique_immut::operator=(unique_immut& r ){
	if(r._mgr == this->_mgr){
		return *this;
	}else{
		this->release();
		*this = r;
		return *this;
}
}
} // end of namespace ptr
