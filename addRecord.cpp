#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
#include <algorithm>
#include "stdInterface.h"
#include "addRecord.h"
using namespace std;

// Function: records the current time the data was inputed
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

int printAddRecord1(int numRow, int numCol, int &sizeArray, record *&records, record &newRecord);

// Function: Lets user input record.type
// Inputs: number of rows for the interface, number of columns for the interface, cin input of record.type
// Outputs: changes record.type
int printAddRecord(int numRow, int numCol, int &sizeArray, record *&records, record &newRecord) {
    int linesOfText = 7;
    while (true) {
        printTopRow(numCol);
        cout << "Add Record" << endl;
        cout << "Please enter the type of income/expense (e.g. food, game, salary, etc.)" << endl;
        cout << "" << endl;
        cout << "Type of income/expense: " << endl;
        cout << "Amount: " << endl;
        cout << "Account: " << endl;
        for (int i = 0; i < numRow - 3 - linesOfText; i++)
            cout << " " << string(numCol,' ') << " " << endl;
        cout << "[x] Cancel" << endl;
        printBottomRow(numCol);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        string input;
        getline(cin,input);
        if (input == "x")
            return 0;
        else {
            newRecord.type = input;
            printAddRecord1(numRow, numCol,sizeArray, records, newRecord);
            return 0;
        }
    }
}

// Function: 
// Inputs: 
// Outputs: 
bool isNumber(string s) {
    string temp = s;
    bool decimal = true;
    if (temp[0] == '-')
        temp.erase(0,1);
    if (temp.length() == 0) {
        return false;
    }
    for (char i : temp) {
        if (!isdigit(i))
            if (i == '.' && decimal) {
                decimal = false;
                continue;
            }
            else
                return false;
    }
    return true;
}

// initialize header to allow use for printAddRecord1
int printAddRecord2(int numRow, int numCol, int &sizeArray, record *&records, record &newRecord);

// Function: Lets user input record.amount
// Inputs: number of rows for the interface, number of columns for the interface, cin input of record.amount
// Outputs: changes record.amount
int printAddRecord1(int numRow, int numCol, int &sizeArray, record *&records, record &newRecord) {
    string input = "0";
    int linesOfText = 7;
    bool error = false;
    while (input != "x") {
        printTopRow(numCol);
        cout << "Add Record" << endl;
        if (error)
            cout << "Error! Please enter a number. ";
        cout << "Please enter the amount (negative for expenses)" << endl;
        cout << "" << endl;
        cout << "Type of income/expense: " + newRecord.type << endl;
        cout << "Amount: " << endl;
        cout << "Account: " << endl;
        for (int i = 0; i < numRow - 3 - linesOfText; i++)
            cout << " " << string(numCol,' ') << " " << endl;
        cout << "[x] Cancel" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == "x")
            return 0;
        if (!isNumber(input))
            error = true;
        else {
            newRecord.amount = stod(input);
            printAddRecord2(numRow, numCol, sizeArray, records, newRecord);
            return 0;
        }
    }
}

int printAddRecord3(int numRow, int numCol, int &sizeArray, record *&records, record &newRecord);

// Function: Lets user input record.account
// Inputs: number of rows for the interface, number of columns for the interface, cin input of record.account
// Outputs: changes record.account
int printAddRecord2(int numRow, int numCol, int &sizeArray, record *&records, record &newRecord) {
    string input = "0";
    while (true) {
        printTopRow(numCol);
        int linesOfText = 7;
        cout << "Add Record" << endl;
        cout << "Please enter the account used (e.g. cash, bank card, credit card, etc.)" << endl;
        cout << "" << endl;
        cout << "Type of income/expense: " + newRecord.type << endl;
        cout << "Amount: " + to_string(newRecord.amount) << endl;
        cout << "Account: " << endl;
        for (int i = 0; i < numRow - 3 - linesOfText; i++)
            cout << " " << string(numCol,' ') << " " << endl;
        cout << "[x] Cancel" << endl;
        printBottomRow(numCol);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,input);
        if (input == "x")
            return 0;
        else {
            newRecord.account = input;
            printAddRecord3(numRow, numCol, sizeArray, records, newRecord);
            return 0;
        }
    }
}

// Function: end stage, press x to quit
// Inputs: number of rows for the interface, number of columns for the interface, cin input of x to quit
// Outputs: exits input of data
int printAddRecord3(int numRow, int numCol, int &sizeArray, record *&records, record &newRecord) { 
    char input;
    int linesOfText = 7;
    while (true) {
        printTopRow(numCol);
        cout << "Add Record" << endl;
        cout << "Record saved! Enter [x] to exit." << endl;
        cout << "" << endl;
        cout << "Type of income/expense: " + newRecord.type << endl;
        cout << "Amount: " + to_string(newRecord.amount) << endl;
        cout << "Account: " + newRecord.account << endl;
        for (int i = 0; i < numRow - 3 - linesOfText; i++)
            cout << " " << string(numCol,' ') << " " << endl;
        cout << "[x] Exit" << endl;
        printBottomRow(numCol);
        timeRecord(newRecord);
        updateRecordsSize(records, sizeArray, 1);
        records[sizeArray-1] = newRecord;
        cin >> input;
        if (input == 'x')
            return 0;
    }
}