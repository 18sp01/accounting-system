all: main

stdInterface:stdInterface.cpp addRecord.cpp viewRecords.cpp
	g++ -pedantic-errors -std=c++11 stdInterface.cpp addRecord.cpp viewRecords.cpp -o stdInterface

fromtoFile:fromtoFile.cpp
	g++ -pedantic-errors -std=c++11 fromtoFile.cpp -o fromtoFile

clean:
	rm stdInterface