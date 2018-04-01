#ifndef GTUSet_H
#define GTUSet_H
using std::cout;
using std::endl;
using std::cerr;
using std::shared_ptr;
#include "GTUSetBase.h"
namespace GTUSetMapRC{

	template <class T>
	class GTUSet : public GTUSetBase<T>{

		public:
			GTUSet();
			GTUSet(int in_capacity);
			GTUSet(const GTUSet & other);

			GTUSet<T> & operator=(const GTUSet<T> &rightSide);
			T& operator [](int index);

			//if used==0 return true
			virtual bool empty() const override;

			//return the used value
			virtual int size() const override;

			//return the capacity value
			virtual int max_size() const override;

			//erase element
			virtual void erase(T element) override;

			//insert the element
			virtual void insert(T element) override;
			
			void printContent() const;
			//clear all content
			virtual void clear() override;
			
			T * find(const T& value);
			int count(const T& value) const override;
			T * begin();
			T * end();
			//if value is exits return true;
			bool itContains(const T& value) const;
			void sort()const;

			shared_ptr<T> array;
			
		protected:

			int capacity;
			int used;
			


		};

}

#endif /* GTUSet_H */
