all: main

main:main.cpp
	g++ -pedantic-errors -std=c++11 main.cpp -o main

clean:
	rm main
