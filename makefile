all: main

stdInterface:stdInterface.cpp addRecord.cpp viewRecords.cpp
	g++ -pedantic-errors -std=c++11 stdInterface.cpp addRecord.cpp viewRecords.cpp -o stdInterface
clean:
	rm stdInterface