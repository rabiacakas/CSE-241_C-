#ifndef GTUSetBase_H
#define GTUSetBase_H
#include <iostream>
#include <memory>
#include "GTUIterator.h"
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::shared_ptr;

namespace GTUSetMapRC{
	
	template<class T>
	class GTUSetBase
	{
		public:

			GTUSetBase();
			GTUSetBase(int in_capacity);
			GTUSetBase(const GTUSetBase & other);

			GTUSetBase<T> & operator =(const GTUSetBase<T> &rightSide);

			int getCapacity() const;
			int getUsed() const;
			void setUsed(int usedVal);

			//if container empty return true
			virtual bool empty() const=0;
			//return the used value
			virtual int size() const=0;
			//return the capacity value
			virtual int max_size() const=0;
			//erase element
			virtual void erase(T element)=0;
			//insert the element
			virtual void insert(T element)=0;

			//clear all content
			virtual void clear()=0;
			virtual T * find(const T& value)=0;
			virtual int count(const T& value) const=0;
			virtual T * begin()=0;
			virtual T * end()=0;

			

		protected:
			int capacity;
			int used;
			shared_ptr<T> array_b;
			
	};
}



#endif /* GTUSetBase_H*/
