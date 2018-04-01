#ifndef GTUMap_H
#define GTUMap_H
#include "GTUSet.h"
using std::pair;
using std::cout;
using std::endl;
using std::cerr;
namespace GTUSetMapRC{
	template <class K, class V>
	class GTUMap: public GTUSet<std::pair<K, V> >{
		
		public:
			GTUMap();
			GTUMap(int capacity);
			V& operator[] (const K& k);
			virtual void insert(K firstElement,V secondElement);
			void printMap();
			int getUsedMap() const;
			void setUsedMap(int in_used);
			void erase(V element);
			bool itContains(const V& value) const;
			//virtual ~GTUMap();
			pair<K, V> * mapTest;
		private:
			
			int capacity_map;
			int used_map;
		};
}


#endif /* GTUMap_H */
