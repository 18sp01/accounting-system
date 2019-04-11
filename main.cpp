#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

// a structure to hold data of records
struct record {
    double amount; // amount of money
    int sec, min, hour, day, month, year; // date and time
    string type; // type of income/expense (e.g. food, game, salary, etc.)
    string account; // account (e.g. cash, bank card, credit card, etc.)
};

// timeRecord: records the current time the data was inputed
// Inputs: record newRecord: the data the time needs to be recorded on
//         local time
// Outputs: data becomes recorded with current time
void timeRecord(record &newRecord) {
    time_t t = time(nullptr);
    tm * tm_local = localtime(&t);
    newRecord.year = tm_local->tm_year + 1900;
    newRecord.month = tm_local->tm_mon + 1;
    newRecord.day = tm_local->tm_mday;
    newRecord.hour = tm_local->tm_hour;
    newRecord.min = tm_local->tm_min;
    newRecord.sec = tm_local->tm_sec;
}

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
}

int main(int argc, char ** argv) {
    vector<record> records;
    return 0;
}