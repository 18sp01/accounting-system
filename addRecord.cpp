#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "stdInterface.h"
#include "addRecord.h"
using namespace std;

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

// Function: int printAddRecord0: Lets user input record.type
// Inputs: number of rows for the interface, number of columns for the interface, cin input of record.type
// Outputs: changes record.type
int printAddRecord0(int numRow, int numCol, record &record) {
    printTopRow(numCol);
    int linesOfText = 7;
    cout << convertStringtoLine("Add Record",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("Please enter type of income/expense (e.g. food, game, salary, etc.)",numCol) << endl;
    cout << convertStringtoLine("Type of income/expense: ",numCol) << endl;
    cout << convertStringtoLine("Amount: ",numCol) << endl;
    cout << convertStringtoLine("Account: ",numCol) << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    cout << convertStringtoLine("[x] Cancel",numCol) << endl;
    printBottomRow(numCol);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    string input;
    getline(cin,input);
    if (input == "x") {
        return 0;
    }
    else {
        record.type = input;
        return 1;
    }
}

// Function: int printAddRecord1: Lets user input record.amount
// Inputs: number of rows for the interface, number of columns for the interface, cin input of record.amount
// Outputs: changes record.amount
int printAddRecord1(int numRow, int numCol, record &record) {
    printTopRow(numCol);
    int linesOfText = 7;
    cout << convertStringtoLine("Add Record",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("Please enter the amount",numCol) << endl;
    cout << convertStringtoLine("Type of income/expense: " + record.type,numCol) << endl;
    cout << convertStringtoLine("Amount: ",numCol) << endl;
    cout << convertStringtoLine("Account: ",numCol) << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    cout << convertStringtoLine("[x] Cancel",numCol) << endl;
    printBottomRow(numCol);
    string input;
    cin >> input;
    if (input == "x") {
        return 0;
    }
    else {
        record.amount = stod(input);
        return 1;
    }
}

// Function: int printAddRecord2: Lets user input record.account
// Inputs: number of rows for the interface, number of columns for the interface, cin input of record.account
// Outputs: changes record.account
int printAddRecord2(int numRow, int numCol, record &record) {
    printTopRow(numCol);
    int linesOfText = 7;
    cout << convertStringtoLine("Add Record",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("Please enter the account used (e.g. cash, bank card, credit card, etc.)",numCol) << endl;
    cout << convertStringtoLine("Type of income/expense: " + record.type,numCol) << endl;
    cout << convertStringtoLine("Amount: " + to_string(record.amount),numCol) << endl;
    cout << convertStringtoLine("Account: ",numCol) << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    cout << convertStringtoLine("[x] Cancel",numCol) << endl;
    printBottomRow(numCol);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    string input;
    getline(cin,input);
    if (input == "x") {
        return 0;
    }
    else {
        record.account = input;
        return 1;
    }
}

// Function: int printAddRecord3: end stage, press x to quit
// Inputs: number of rows for the interface, number of columns for the interface, cin input of x to quit
// Outputs: exits input of data
int printAddRecord3(int numRow, int numCol, record &record) {
    printTopRow(numCol);
    int linesOfText = 7;
    cout << convertStringtoLine("Add Record",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("Record Saved! Enter [x] to exit.",numCol) << endl;
    cout << convertStringtoLine("Type of income/expense: " + record.type,numCol) << endl;
    cout << convertStringtoLine("Amount: " + to_string(record.amount),numCol) << endl;
    cout << convertStringtoLine("Account: " + record.account,numCol) << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    cout << convertStringtoLine("[x] Exit",numCol) << endl;
    printBottomRow(numCol);
    char input;
    cin >> input;
    while (input != 'x') {
        cin >> input;
    }
}

// Function: prinAddRecord: Prompt AddRecord interface
// Inputs: cin input of all record parameters
// Outputs: adds a new record to records
void printAddRecord(int numRow, int numCol, vector<record> &records, record &newRecord) {
    if (printAddRecord0(numRow, numCol,newRecord) != 0) {
        if (printAddRecord1(numRow, numCol,newRecord) != 0) {
            if (printAddRecord2(numRow, numCol,newRecord) != 0) {
                printAddRecord3(numRow, numCol,newRecord);
                timeRecord(newRecord);
                records.push_back(newRecord);
            }
        }
    }
}