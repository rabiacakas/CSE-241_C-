#include "GTUSetBase.h"
namespace GTUSetMapRC{
	//No parameter constructor ile olusturulan objede max_capacity 50 olarak belirlendi, used=0 olarak olusturuldu
	template <class T>
	GTUSetBase<T>::GTUSetBase(){
	    capacity=50;
	    used=0;
	    
	}
	//Capacity alarak olusturulan objede max_capacity kullanıcı tarafından belirlendi
	template <class T>
	GTUSetBase<T>::GTUSetBase(int in_capacity){
		capacity = in_capacity;
		used=0;
	}
	//Copy constructor
	template <class T>
	GTUSetBase<T>::GTUSetBase(const GTUSetBase<T> & other){

		capacity= other.capacity;
		used= other.used;
		shared_ptr<T>array_b(new T[capacity]);
		for(int i=0; i< used; i++){
			array_b[i]= other.array_b[i];
		}
	}
	//Assignment operator
	template <class T>
	GTUSetBase<T>& GTUSetBase<T>::operator =(const GTUSetBase<T> &rightSide){
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
	//Returns capacity
	template <class T>
	int GTUSetBase<T>::getCapacity() const{
		return capacity;
	}
	//Returns used value
	template <class T>
	int GTUSetBase<T>::getUsed() const{
		return used;
	}
	template <class T>
	void GTUSetBase<T>::setUsed(int usedVal){
		used=usedVal;
	}
}
