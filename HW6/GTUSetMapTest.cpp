/***********************************************************
*	Rabia ÇAKAS, 141044042, HW06 C++ 2017				   *
************************************************************
* 	GTUSetBase abstract class indan turemis GTUSet<T> 	   *
* ve GTUMap<T> class larini kullanarak set ve map container* 
* lari implement eder.									   *
************************************************************
* shared_ptr<GTUSet<T>>setIntersection(GTUSet<T> & firstSet*
* GTUSet<T> & secondSet) fonksiyonu iki GTUSet objesi alir,*
* ortak elemanlarini bulur ve ortak eleman sayisinda yeni  *
* obje olusturup return eder.							   *
************************************************************
* shared_ptr<GTUMap<K,V>>setIntersection(GTUMap<K,V> &     *
* firstMap, GTUMap<K,V> & secondMap) fonksiyonu iki GTUMap *
* objesi alir, ortak elemanlarini bulur ve ortak eleman    *
* sayisinda yeni obje olusturup return eder.			   *
************************************************************/
#include <iostream>
#include <memory>
#include <algorithm>
#include <stdexcept>

#include "GTUSetBase.cpp"
#include "GTUSet.cpp"
#include "GTUMap.cpp"
using std::shared_ptr;
using namespace GTUSetMapRC;

template <class T>
shared_ptr<GTUSet<T>>setIntersection(GTUSet<T> & firstSet, GTUSet<T> & secondSet){
	int count=0;
	cout<<"Intersection for first and second set: ";
	for(int i=0; i<firstSet.getUsed(); i++){
		for(int j=0; j<secondSet.getUsed(); j++){
			if(firstSet.array.get()[i]==secondSet.array.get()[j]){
				cout<<firstSet.array.get()[i]<<" ";
				count++;
				break;
			}

		}
	}
	cout<<endl;
	return std::make_shared<GTUSet<T> >(count);
}

template <class K, class V>
shared_ptr<GTUMap<K,V>>setIntersection(GTUMap<K,V> & firstMap, GTUMap<K,V> & secondMap){
	int count=0;
	cout<<"Intersection for first and second map: ";
	for(int i=0; i<firstMap.getUsedMap(); i++){
		for(int j=0; j<secondMap.getUsedMap(); j++){
			if(firstMap.mapTest[i].first==secondMap.mapTest[j].first && firstMap.mapTest[i].second==secondMap.mapTest[j].second){
				cout<<firstMap.mapTest[i].first<<" "<<firstMap.mapTest[i].second<<" ";
				count++;
				break;
			}

		}
	}
	cout<<endl;
	return std::make_shared<GTUMap<K,V> >(count);
}
int main(int argc, char const *argv[])
{
	
	GTUSet<int> object(20);
	GTUSet<int> object2;
	GTUSet<string> setStr;
	GTUSet<double> setDouble;
	GTUSet<char> setChr;

	cout<<"------------ FOR GTUSet<T> TESTING... ------------\n"<<endl;
	cout<<"The capacity of int object: "<<object.getCapacity()<<endl;
	cout<<"Is empty ( 1(true) / 0(false) )?"<<object.empty()<<endl;
	cout<<"Used element of object: "<<object.getUsed()<<endl;
	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"The capacity of int object2: "<<object2.getCapacity()<<endl;
	cout<<"Is empty ( 1(true) / 0(false) )?"<<object2.empty()<<endl;
	cout<<"Used element of object: "<<object2.getUsed()<<endl;
	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"The capacity of string setStr: "<<setStr.getCapacity()<<endl;
	cout<<"Is empty ( 1(true) / 0(false) )?"<<setStr.empty()<<endl;
	cout<<"Used element of setStr: "<<setStr.getUsed()<<endl;
	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"The capacity of double setDouble: "<<setDouble.getCapacity()<<endl;
	cout<<"Is empty ( 1(true) / 0(false) )?"<<setDouble.empty()<<endl;
	cout<<"Used element of setDouble: "<<setDouble.getUsed()<<endl;
	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"The capacity of char setChr: "<<setChr.getCapacity()<<endl;
	cout<<"Is empty ( 1(true) / 0(false) )?"<<setChr.empty()<<endl;
	cout<<"Used element of setChr: "<<setChr.getUsed()<<endl;
	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"TRY THE INSERT ELEMENT IN object, object2 and setStr.."<<endl;
	try{
		object.insert(10);
		object.insert(20);
		object2.insert(20);
		object2.insert(10);
		object2.insert(30);
		object2.insert(40);

		setStr.insert("Rabia");
		setStr.insert("Çakas");
		setStr.insert("C++");
		setStr.insert("HW6");
		setStr.insert("2017");
		setStr.insert("OOP");
		setDouble.insert(2.3);
		setDouble.insert(1.7);
		setChr.insert('R');
		object2.insert(40);
	}
	catch(const std::invalid_argument& e){
	  cerr<<"Invalid argument: "<<e.what()<<endl;
  	}
  	cout<<endl;
  	cout<<"-------------------------------------------------\n"<<endl;
  	cout<<"IN object CONTENT: ";
  	object.printContent();
  	cout<<"IN object2 CONTENT: ";
  	object2.printContent();
  	cout<<"IN setStr CONTENT: ";
  	setStr.printContent();
  	cout<<"IN setDouble CONTENT: ";
  	setDouble.printContent();
  	cout<<"IN setChr CONTENT: ";
  	setChr.printContent();
  	cout<<endl;

  	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"After insert object size: "<<object.size()<<endl;
	cout<<"After insert object2 size: "<<object2.size()<<endl;
	cout<<"After insert setStr size: "<<setStr.size()<<endl;
	cout<<"After insert setDouble size: "<<setDouble.size()<<endl;
	cout<<"After insert setChr size: "<<setChr.size()<<endl;
  	cout<<"-------------------------------------------------\n"<<endl;
  	cout<<"TEST FOR setIntersection(object, object2)"<<endl;
	setIntersection(object, object2);
	cout<<endl;
	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"TRY THE ERASE ELEMENT object, object2 AND setStr.."<<endl;
	try{
		object.erase(10);
		object2.erase(10);
		setStr.erase("OOP");
		setStr.erase("Y.Sinan AKGUL");
	}
	catch(const std::invalid_argument& e){
	  cerr<<"Invalid argument: "<<e.what()<<endl;
  	}
  	cout<<"IN object CONTENT: ";
  	object.printContent();
  	cout<<"IN object2 CONTENT: ";
  	object2.printContent();
  	cout<<"IN setStr CONTENT: ";
  	setStr.printContent();
	cout<<"After erase element object size:"<<object.size()<<endl;
	cout<<"After erase element object2 size:"<<object2.size()<<endl;
	cout<<"After erase element setStr size:"<<setStr.size()<<endl;
  	cout<<endl;
	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"TEST FOR ITERATOR FUNCTION.. with begin(), end() PRINT CONTENT"<<endl;
	int * i;
	for(i=object2.begin(); i!=object2.end(); i++){
		cout<<*i<<" ";
	}
	cout<<endl;
	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"TEST FOR setIntersection(object, object2)"<<endl;
	setIntersection(object, object2);
	cout<<endl;
	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"TEST FOR clear() FUNCTION ON object AND object2"<<endl;
	object2.clear();
	object.clear();
	setStr.clear();
	cout<<"After clear() function object2.size(): "<<object2.size()<<endl;
	cout<<"After clear() function object.size(): "<<object.size()<<endl;
	cout<<"After clear() function setStr.size(): "<<setStr.size()<<endl;

	
	GTUMap<int, int> objectMap;
	GTUMap<int, int> objectMap2(30);
	GTUMap<double, double> objectMapDouble(20);
	GTUMap<char, char> objectMapchr(20);
	GTUMap<string, string> objectMapstr(10);

	cout<<endl;
	cout<<"------------ FOR GTUMap<K, V> TESTING... ------------\n"<<endl;
	
	cout<<"TRY THE INSERT ELEMENT IN objectMap, objectMap2, objectMapDouble, objectMapchr, objectMapstr."<<endl;
	try{
		objectMap.insert(10,20);
		objectMap.insert(30,40);
		objectMap.insert(50,60);
		objectMap.insert(70,80);
		
		objectMap2.insert(50,60);
		objectMap2.insert(10,20);
		objectMap2.insert(18,86);

		objectMapDouble.insert(1.7, 2.3);
		objectMapDouble.insert(8.9, 6.5);

		objectMapchr.insert('r', 'c');
		objectMapchr.insert('o', 'b');

		objectMapstr.insert("Rabia", "ÇAKAS");
		objectMapstr.insert("M.Fatih", "TUNALİ");
		objectMapstr.insert("Y.Sinan", "AKGUL");

	}
	catch(const std::invalid_argument& e){
	  cerr<<"Invalid argument: "<<e.what()<<endl;
  	}

  	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"AFTER INSERT ELEMENT IN MAPS: "<<endl;
  	
  	cout<<"IN objectMap CONTENT: ";
	objectMap.printMap();
	cout<<endl;
	cout<<"IN objectMap2 CONTENT: ";
	objectMap2.printMap();
	cout<<endl;
	cout<<"IN objectMapDouble CONTENT: ";
	objectMapDouble.printMap();
	cout<<endl;
	cout<<"IN objectMapchr CONTENT: ";
	objectMapchr.printMap();
	cout<<endl;
	cout<<"IN objectMapstr CONTENT: ";
	objectMapstr.printMap();
	cout<<endl;
	cout<<"-------------------------------------------------\n"<<endl;

	cout<<"TRY THE ERASE ELEMENT IN objectMap, objectMap2, objectMapDouble, objectMapchr AND objectMapstr.."<<endl;
	try{
		objectMap.erase(40);
		objectMap2.erase(60);
		objectMapDouble.erase(6.5);
		objectMapchr.erase('c');
		objectMapstr.erase("AKGUL");
		objectMapstr.erase("c++");
	}
	catch(const std::invalid_argument& e){
	  cerr<<"Invalid argument: "<<e.what()<<endl;
  	}
  	cout<<"After the erase element in maps content: "<<endl;
  	cout<<"IN objectMap CONTENT: ";
  	objectMap.printMap();
  	cout<<endl;
  	cout<<"IN objectMap2 CONTENT: ";
  	objectMap2.printMap();
  	cout<<endl;
  	cout<<"IN objectMapDouble CONTENT: ";
  	objectMapDouble.printMap();
  	cout<<endl;
  	cout<<"IN objectMapchr CONTENT: ";
  	objectMapchr.printMap();
  	cout<<endl;
  	cout<<"IN objectMapstr CONTENT: ";
  	objectMapstr.printMap();
  	cout<<endl;
  	cout<<"-------------------------------------------------\n"<<endl;
	cout<<"TEST FOR setIntersection(objectMap, objectMap2)"<<endl;
	setIntersection(objectMap,objectMap2);
	cout<<endl;
	return 0;
}
