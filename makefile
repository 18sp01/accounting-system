all: stdInterface

stdInterface:stdInterface.cpp addRecord.cpp viewRecords.cpp fromtoFile.cpp sortRecords.cpp editRecords.cpp
	g++ -pedantic-errors -std=c++11 stdInterface.cpp addRecord.cpp viewRecords.cpp fromtoFile.cpp sortRecords.cpp editRecords.cpp -o stdInterface

clean:
	rm stdInterface