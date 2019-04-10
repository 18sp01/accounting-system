interface:interface.cpp
	g++ -pedantic-errors -std=c++11 interface.cpp -o interface -lncurses

main:main.cpp
	g++ -pendantic-errors -std=c++11 main.cpp -o main
