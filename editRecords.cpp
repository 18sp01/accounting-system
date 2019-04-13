#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include "stdInterface.h"
#include "editRecords.h"
using namespace std;

// removeRecord: remove record from records
// Inputs: vector<record> &records: vector of records
//         int index: index of record to be removed
// Outputs: 
void removeRecord (vector<record> &records, int index) {
    records.erase(records.begin() + index);//
}

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
