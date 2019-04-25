all: stdInterface

stdInterface:stdInterface.cpp addRecord.cpp viewRecords.cpp fromtoFile.cpp sortRecords.cpp editRecords.cpp filterRecords.cpp statReport.cpp statGraphs.cpp budgeting.cpp
	g++ -pedantic-errors -std=c++11 stdInterface.cpp addRecord.cpp viewRecords.cpp fromtoFile.cpp sortRecords.cpp editRecords.cpp filterRecords.cpp statReport.cpp statGraphs.cpp budgeting.cpp -o stdInterface

clean:
	rm stdInterface