#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include "editRecords.h"
using namespace std;

// addRecord: adds the data to vector of record
// Inputs: vector<record> &records: vector of records
//         user input
// Outputs: new data record
void addRecord (vector<record> &records) {
    record newRecord;
    cin >> newRecord.amount >> newRecord.type >> newRecord.account;
    timeRecord(newRecord);
    records.push_back(newRecord);
}

// removeRecord: remove record from records
// Inputs: vector<record> &records: vector of records
//         int index: index of record to be removed
// Outputs: 
void removeRecord (vector<record> &records, int index) {
    records.erase(records.begin() + index);//
}

// sortVector: sort vector in a specific order
// Inputs: vector<record> records: vector of records
//         string sortType: type of sort
//         bool descend: sort in descending order
// Outputs: 
void sortVector (vector<record> &records, string sortType, bool descend = false) {
    
}

// printVector
void printVector(vector<record> records) {
    cout << records.size() << endl;
    for (record i : records) {
        cout << i.amount << " " << i.year << "/" << i.month << "/" << i.day << " " << i.type << "," << i.account << endl;
    }
}

// prints time of record
void printTime(record record) {
    cout << record.year << '/' << record.month << '/' << record.day << ' ' << record.hour << ':' << record.min << ':' << record.min << endl;
// addRecord: adds the data to vector of record
// Inputs: vector<record> &records: vector of records
//         user input
// Outputs: new data record/ addRecord: adds the data to vector of record
// Inputs: vector<record> &records: vector of records
//         user input
// Outputs: new data record
void addRecord (vector<record> &records) {
    record newRecord;
    cin >> newRecord.amount >> newRecord.type >> newRecord.account;
    timeRecord(newRecord);
    records.push_back(newRecord);
}

// removeRecord: remove record from records
// Inputs: vector<record> &records: vector of records
//         int index: index of record to be removed
// Outputs: 
void removeRecord (vector<record> &records, int index) {
    records.erase(records.begin() + index);//
}

// sortVector: sort vector in a specific order
// Inputs: vector<record> records: vector of records
//         string sortType: type of sort
//         bool descend: sort in descending order
// Outputs: 
void sortVector (vector<record> &records, string sortType, bool descend = false) {
    
}

// printVector
void printVector(vector<record> records) {
    cout << records.size() << endl;
    for (record i : records) {
        cout << i.amount << " " << i.year << "/" << i.month << "/" << i.day << " " << i.type << "," << i.account << endl;
    }
}

// prints time of record
void printTime(record record) {
    cout << record.year << '/' << record.month << '/' << record.day << ' ' << record.hour << ':' << record.min << ':' << record.min << endl;
}