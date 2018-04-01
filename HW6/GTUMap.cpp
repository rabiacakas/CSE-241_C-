#include "GTUMap.h"
using std::pair;
namespace GTUSetMapRC{
	//GTUSet<pair<K, V>> olarak pair array leri seklinde capacity kadar yer alındı.
	template <class K, class V>
	GTUMap<K,V>::GTUMap()
	{
		capacity_map=50;
		used_map=0;
		mapTest=new pair<K,V>[capacity_map];
	}
	template <class K, class V>
	GTUMap<K,V>::GTUMap(int in_capacity)
	{
		capacity_map=in_capacity;
		used_map=0;
		mapTest=new pair<K,V>[capacity_map];
	}
	//Index operator: Eger gelen k degeri pair in first elemanıyla eslesiyorsa ilgili second ı return eder.
	template <class K, class V>
	V& GTUMap<K,V>::operator[] (const K& k){ 
		if(mapTest[getUsedMap()].first==k){
			return mapTest[k];
		}
	}
	//Key degeri pair daki baska bir key ile eslesmiyorsa gelen K, V degerleri pair a eklenir
	//Eger key pair da varsa exception fırlatılır.
	template <class K, class V>
	void GTUMap<K,V>::insert(K firstElement, V secondElement){
		if(mapTest[getUsedMap()].first!=firstElement){
			mapTest[getUsedMap()].first=firstElement;
			mapTest[getUsedMap()].second=secondElement;
			setUsedMap(getUsedMap()+1);

		}
		else{
			throw std::invalid_argument("COULD NOT EXISTING KEY ELEMENT INSERT !!");
		}
	}
	//Map contentini basar
	template <class K, class V>
	void GTUMap<K,V>::printMap(){
		for(int i=0; i<getUsedMap(); i++){
			cout<<mapTest[i].first<<" "<<mapTest[i].second<<" ";
		}
		
	}
	template<class K, class V>
	int GTUMap<K,V>::getUsedMap() const{
		return used_map;
	}
	template <class K, class V>
	void GTUMap<K,V>::setUsedMap(int in_used){
		used_map=in_used;
	}
	//Key degeri pair daki baska bir key ile eslesiyorsa gelen K, V degerleri pair dan cikarilir
	//Eger key pair da yoksa exception fırlatılır.
	template <class K, class V>
	void GTUMap<K,V>::erase(V element){
		if(!itContains(element)){
			throw std::invalid_argument("COULD NOT EXISTING ELEMENT ERASE !!");
		}
		else if(itContains(element)){
			int i, j;
			for(i=0; i<this->getUsedMap(); i++){
				if(mapTest[i].second==element){
					break;
				}
			}
			for(j=i; j<this->getUsed()-1; j++){
				mapTest[j].first=mapTest[j+1].second;
				mapTest[j].second=mapTest[j+1].second;
			}
			this->setUsedMap(this->getUsedMap()-1);
		}
	}
	//Eger value pair da varsa true return eder.
	template <class K, class V>
	bool GTUMap<K,V>::itContains(const V& value) const{
		bool isContains=false;
		for(int i=0; i<this->getUsedMap(); i++){
			if(mapTest[i].second==value){
				isContains=true;
				break;
			}
		}
		return isContains;
	}
}
