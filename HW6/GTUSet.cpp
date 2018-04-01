#include "GTUSet.h"
namespace GTUSetMapRC{
	//GTUSetBase class ında ataması yapılan capacity degerine gore array icin yer alındı.
	//std::default_delete<T[]>(), C++ 11 standardına gore memory_leak olmaması icin eklendi.
	template <class T>
	GTUSet<T>::GTUSet()
	   :GTUSetBase<T>()
	{
		array=shared_ptr<T>(new T[this->getCapacity()], std::default_delete<T[]>() );
	}

	template <class T>
	GTUSet<T>::GTUSet(int in_capacity)
	   :GTUSetBase<T>(in_capacity)
	{
		array=shared_ptr<T>(new T[this->getCapacity()], std::default_delete<T[]>() );
	}
	//Her eleman eklendiginde used degeri arttırıldı. Used=0 ise true return edildi.
	template <class T>
	bool GTUSet<T>::empty() const{
		if(this->getUsed()==0){
			return true;
		}
		return false;
	}

	template <class T>
	int GTUSet<T>::size() const{
		return this->getUsed();
	}

	template <class T>
	int GTUSet<T>::max_size() const{
		return this->getCapacity();;
	}
	//Assignment operator
	template <class T>
	GTUSet<T>& GTUSet<T>::operator = (const GTUSet<T>& rightSide){
		if(&rightSide==this){
	        return *this;
		}

		delete [] array;	
	    if(capacity !=rightSide.capacity) {
	        capacity=rightSide.capacity;
	    }
	    used= rightSide.used;

	    array=shared_ptr<T>(new T[this->getCapacity()]);

	    for(int i= 0; i<this->getUsed(); i++) {
	        array[i] = rightSide.array[i];
	    }
	}
	//Index operator: Eger index olması gereken sınırlar arasındaysa array in ilgili elemanını return eder.
	template <class T>
	T& GTUSet<T>:: operator [](int index){
		if(index>=this->getCapacity() || index>=this->getUsed() || index<0){
			cerr<<"Wrong index number, please control this !"<<endl;
			exit(1);
		}

		return array[index];
	}
	//Eger array icerisinde ilgili eleman yoksa gelen argumanı array e atar, varsa exception (std::invalid_argument) fırlatır.
	//Her basarili insert isleminden sonra used 1 arttırılır.
	//Set icerisinde elemanların sıralı olması icin sort() fonksiyonu her insert isleminden sonra yapılır.
	template <class T>
	void GTUSet<T>::insert(T element){

		if(this->getUsed() >=this->getCapacity()){
			cout<<"Full of max_capacity for set container !"<<endl;
			exit(1);
		}
		if(!itContains(element)){
			array.get()[this->getUsed()] = element;
			this->setUsed(this->getUsed()+1);
			sort();
		}
		else if(itContains(element)){
			throw std::invalid_argument("COULD NOT EXISTING ELEMENT INSERT !!");
		}
		
	}
	//Eger array icerisinde ilgili eleman varsa gelen argumanı array den siler, yoksa exception (std::invalid_argument) fırlatır.
	//Her basarili erase isleminden sonra used 1 azaltilir.
	template <class T>
	void GTUSet<T>::erase(T element){
		if(!itContains(element)){
			throw std::invalid_argument("COULD NOT EXISTING ELEMENT ERASE !!");
		}
		else if(itContains(element)){
			int i, j;
			for(i=0; i<this->getUsed(); i++){
				if(array.get()[i]==element){
					break;
				}
			}
			for(j=i; j<this->getUsed()-1; j++){
				array.get()[j]=array.get()[j+1];
			}
			this->setUsed(this->getUsed()-1);
		}

	}
	//Array in baslangic adresini array[0] i return eder.
	template <class T>
	T * GTUSet<T>::begin(){
		T * ptr;
		ptr = &(*array);
		return ptr;
	}
	//Array in eklenen son elemanindan bir sonraki adresi return eder.
	template <class T>
	T * GTUSet<T>::end(){
		T * ptr;
		ptr= &(array.get()[this->getUsed()]);
		return ptr;
	}
	//Array in aranan elemaninin adresini return eder.
	template <class T>
	T * GTUSet<T>::find(const T& value){
		T * ptr;
		int i;
		bool isContains=false;
		for(i=0; i<this->getCapacity(); i++){
			if(array.get()[i]==value){
				isContains=true;
				break;
			}
		}
		ptr =&(array.get()[i]);
		return ptr;
	}
	//Array icerisinde ilgili eleman varsa true return eder.
	template <class T>
	bool GTUSet<T>::itContains(const T& value) const{
		bool isContains=false;
		for(int i=0; i<this->getCapacity(); i++){
			if(array.get()[i]==value){
				isContains=true;
				break;
			}
		}
		return isContains;
	}
	//Set icerisindeki value sayısını return eder.
	template <class T>
	int GTUSet<T>::count(const T& value) const{
		int count=0;
		for(int i=0; i<this->getCapacity(); i++){
			if(array.get()[i]==value){
				count++;
			}
		}
		//cout<<"count: "<<count<<endl;
		return count;
	}
	//Array content ini print eder.
	template <class T>
	void GTUSet<T>::printContent() const{
		for(int i=0; i<this->getUsed(); i++){
			cout<<array.get()[i]<<" ";
		}
		cout<<endl;
	}
	//Array sort
	template <class T>
	void GTUSet<T>::sort()const{
		T temp;
		for(int i=0; i<this->getUsed(); i++){
			for(int j=i+1; j<this->getUsed(); j++){
				if(array.get()[j] < array.get()[i]){
					temp=array.get()[i];
					array.get()[i]=array.get()[j];
					array.get()[j]=temp;
				}
			}
		}
	}
	//Content i tamamen siler.
	template <class T>
	void GTUSet<T>::clear(){
		this->setUsed(0);
	}
}
