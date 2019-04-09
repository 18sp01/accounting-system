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
void timeRecord(record newRecord) {
    time_t t = time(NULL);
    tm * tm_local = localtime(&t);
    newRecord.year = tm_local->tm_year;
    newRecord.month = tm_local->tm_mon;
    newRecord.day = tm_local->tm_mday;
    newRecord.hour = tm_local->tm_hour;
    newRecord.min = tm_local->tm_min;
    newRecord.sec = tm_local->tm_sec;
}

// addRecord: adds the data to vector of record
// Inputs: vector<record> records: vector of records
//         user input
// Outputs: new data record
void addRecord (vector<record> records) {
    record newRecord;
    cin >> newRecord.amount >> newRecord.type >> newRecord.account;
    timeRecord(newRecord);
    records.push_back(newRecord);
}

int main() {
    vector<record> records;
    
}