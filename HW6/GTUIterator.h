#ifndef GTUIterator_H
#define GTUIterator_H
using std::cout;
using std::endl;
using std::cin;
namespace GTUSetMapRC{
	template <class T>
	class GTUIterator
	{
		public:
			
			GTUIterator();
			T & operator =(const T & rightSide);
			bool operator ==(const T & other);
			T & operator ++();
			T & operator ++(int ignoreMe);
			T & operator --();
			T & operator --(int ignoreMe);
			T & operator *();
			T & operator ->();
			
	};

}



#endif /* GTUIterator_H */
