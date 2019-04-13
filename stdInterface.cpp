#include <iostream>
#include <string>
#include <vector>
#include "stdInterface.h"
#include "editRecords.h"
#include "addRecord.h"
#include "viewRecords.h"
#include "fromtoFile.h"
#include "sortRecords.h"
using namespace std;

// Function: 
// Inputs: 
// Outputs: 
void printTopRow(int numCol) {
    cout << string(numCol+2,'#') << endl;
}

// Function: 
// Inputs: 
// Outputs: 
void printBottomRow(int numCol) {
    cout << string(numCol+2,'#') << endl;
}

// Function: 
// Inputs: 
// Outputs: 
void printMainMenu(int numRow, int numCol) {
    printTopRow(numCol);
    int linesOfText = 8;
    cout << "Easy Accounting System" << endl;
    cout << "by Tam Fong Ching Herbert and Park Sangwon" << endl;
    cout << "" << endl;
    cout << "Please enter a command:" << endl;
    cout << "[a] Add Record" << endl;
    cout << "[v] View Records" << endl;
    cout << "[s] Statistics" << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << string(numCol,' ') << endl;
    cout << "[x] Exit" << endl;
    printBottomRow(numCol);
}

int main(int argc, char ** argv) {
    int numCol = 100;
    int numRow = 12;

    vector<record> records;

    readFromFile(records);
    printMainMenu(numRow, numCol);
    char command;
    cin >> command;
    while (command != 'x') {
        switch (command) {
            case 'a': {
                record newRecord;
                printAddRecord(numRow, numCol, records, newRecord);
                break;
            }
            case 'v': {
                viewRecordPages(numRow, numCol, records);
                break;
            }
            case 's': {
                break;
            }
        }
        printMainMenu(numRow, numCol);
        cin >> command;
    }
    writeToFile(records);
}