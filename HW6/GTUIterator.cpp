#include "GTUIterator.h"
namespace GTUSetMapRC{
	
	template <class T>
	T & GTUIterator::operator =(const T & rightSide){
		if(&rightSide==this){
	        return *this;
		}
		delete [] array_b;	
	    if(capacity !=rightSide.capacity) {
	        capacity=rightSide.capacity;
	    }
	    used= rightSide.used;

	    shared_ptr<T>array_b(new T[capacity]);

	    for(int i= 0; i< used; i++) {
	        array_b[i] = rightSide.array_b[i];
	    }

	}
	template <class T>
	T& GTUIterator::operator ++()
	{
		used++;
		capacity++;
		*T++;
	    return *this;
	}
	template <class T>
	T& GTUIterator::operator --()
	{
		used--;
		capacity--;
		*T--;
	    return *this;
	}
	template <class T>
	T& GTUIterator::operator ++(int ignoreMe)
	{
	    T temp(*this);
	    operator++();
	    return temp;
	}
	template <class T>
	T& GTUIterator::operator --(int ignoreMe)
	{
	    T temp(*this);
	    operator--();
	    return temp;
	}
	bool GTUIterator::operator ==(const T & other){
		bool flag=false;
		if(this->getUsed()==other->getUsed() && this->getCapacity()==other.getCapacity()){
			flag=true;
		}
		if(flag){
			for(int i=0; i<this->getUsed(); i++){
				if(array.get()[i]!=other.array.get()[i]){
					return false;
				}
			}
			return true;
		}
	}
	template <class T>
	T & GTUIterator::operator ->(){
		return &T;
	}
	template <class T>
	T & GTUIterator::operator *(){
		return T*;
	}
}