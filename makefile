all: main

stdInterface:stdInterface.cpp addRecord.cpp records.cpp
	g++ -pedantic-errors -std=c++11 stdInterface.cpp addRecord.cpp records.cpp -o stdInterface
clean:
	rm stdInterface