#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "stdInterface.h"
#include "fromtoFile.h"
using namespace std;

// Function: readFromFile: reads records data from data.txt, and updates dynamic array records
// Inputs: reference to dynamic array records, reference to size of records
// Outputs: changes to records, changes to sizeArray
void readFromFile(int &sizeArray, record *&records) {
    ifstream fin;
    fin.open("data.txt");

    // fail safe just in case program fails to open data.txt
    if(fin.fail()) {
        cout << "data.txt not found! Please create a new empty data.txt if this message appears." << endl;
        exit(1);
    }

    string line;
    string amount, type, account, day, month, year, hour, min, sec;
    while (getline(fin, line)) {
        // gets comma-separated info
        getline(fin, amount, ',');
        getline(fin, type, ',');
        getline(fin, account, ',');
        getline(fin, day, ',');
        getline(fin, month, ',');
        getline(fin, year, ',');
        getline(fin, hour, ',');
        getline(fin, min, ',');
        getline(fin, sec, ',');
        
        // creates a newRecord to store the data
        record newRecord;
        double d = stod(amount);
        newRecord.amount = d;
        newRecord.type = type;
        newRecord.account = account;
        newRecord.day = stoi(day);
        newRecord.month = stoi(month);
        newRecord.year = stoi(year);
        newRecord.hour = stoi(hour);
        newRecord.min = stoi(min);
        newRecord.sec = stoi(sec);
        // increases sizeArray by one then appends newRecords to the array
        updateRecordsSize(records, sizeArray, 1);
        records[sizeArray-1] = newRecord;
    }

    fin.close();
}

// Function: writeToFile: reads records data from dynamic array records, and updates data.txt
// Inputs: dynamic array records, size of records
// Outputs: updates data.txt
void writeToFile(int sizeArray, record *records) {
    ofstream fout;
    fout.open("data.txt", ofstream::trunc); // clears data.txt to prepare writing

    // fail safe just in case data.txt is not found
    if(fout.fail()) {
        cout << "data.txt not found! Please create a new empty data.txt if this message appears." << endl;
        exit(1);
    }
    fout << "Amount,Type,Account,Day,Month,Year,Hour,Minutes,Seconds" << endl; // first line of data.txt
    for (int i = 0; i < sizeArray; i++) {
        if (i != 0)
            fout << endl; // makes sure no new line is created after all the records in written to the file
        fout << records[i].amount << ',' << records[i].type << ',' << records[i].account << ',' << records[i].day << ',' << records[i].month << ',' << records[i].year << ',' << records[i].hour << ',' << records[i].min << ',' << records[i].sec << ',';
    }
    fout.close();
}