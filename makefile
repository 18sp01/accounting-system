all: main

main:main.cpp
	g++ -pedantic-errors -std=c++11 main.cpp interface.cpp -o main -lncurses

clean:
	rm main
