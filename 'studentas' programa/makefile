CXXFLAGS=-O3 -std=c++17 -Wno-deprecated-declarations
main: v3.0.o
	g++ $(CXXFLAGS) -o prog myfunc.cpp v3.0.cpp
v3.0.o: v3.0.cpp
	g++ -c $(CXXFLAGS) v3.0.cpp
func:
	g++ -g myfunc.cpp
clean: 
	rm *.o prog
del:
	- rm *\(v1\).txt
	- rm *\(v2\).txt
	- rm *\(l1\).txt
	- rm *\(l2\).txt
	- rm *\(d1\).txt
	- rm *\(d2\).txt
