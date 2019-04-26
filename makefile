all: eas

eas:stdInterface.cpp addRecord.cpp viewRecords.cpp fromtoFile.cpp sortRecords.cpp editRecords.cpp filterRecords.cpp statReport.cpp statGraphs.cpp budgeting.cpp
	g++ -pedantic-errors -std=c++11 stdInterface.cpp addRecord.cpp viewRecords.cpp fromtoFile.cpp sortRecords.cpp editRecords.cpp filterRecords.cpp statReport.cpp statGraphs.cpp budgeting.cpp -o eas

clean:
	rm eas