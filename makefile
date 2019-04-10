all: interface main

interface:interface.cpp
	g++ -pedantic-errors -std=c++11 interface.cpp -o interface -lncurses

main:main.cpp
	g++ -pedantic-errors -std=c++11 main.cpp -o main

clean:interface main
	rm interface main
