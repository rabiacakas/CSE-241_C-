all: hello

hello: GTUSetMapTest.o
	g++ GTUSetMapTest.o -o exe

GTUSetMapTest.o: GTUSetMapTest.cpp
	g++ -c -std=c++11 GTUSetMapTest.cpp

clean:
	rm *.o exe
