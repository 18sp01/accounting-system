#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "stdInterface.h"
#include "addRecord.h"
#include "viewRecords.h"
#include "editRecords.h"
using namespace std;

// Function: int printVector: prints data inside records
// Inputs: number of rows for the interface, number of columns for the interface, vector of records
// Outputs: prints records
// Example:
// 1 | Amount: 9998 | Type: Dinner Ingredient | Account: Credit Card | Date: 12 4 2019 12:23
// 2 | Amount: 102 | Type: Food | Account: Bank | Date: 12 4 2019 14:09
// Num | Amount | Type | Account | Date
// 2 | 102 | Food | Bank | 12 4 2019 14:09

int listRecords(int numRow, int numCol, vector<record> records, int page) {
    int usedLines = 6;
    int maxI;
    if (records.size() - page*(numRow - usedLines) < numRow - usedLines)
        maxI = records.size() - page*(numRow - usedLines);
    else
        maxI = numRow - usedLines;
    for (int i = 0; i < maxI; i++) {
        cout << " " << i+(page*(numRow - usedLines))+1 << " | ";
        cout << "Amount: " << records[i+(page*(numRow - usedLines))].amount << " | ";
        cout << "Type: " << records[i+(page*(numRow - usedLines))].type << " | ";
        cout << "Account: " << records[i+(page*(numRow - usedLines))].account << " | ";
        cout << "Date: " << records[i+(page*(numRow - usedLines))].day << " " << records[i+(page*(numRow - usedLines))].month << " " << records[i+(page*(numRow - usedLines))].year << " " << records[i+(page*(numRow - usedLines))].hour << ":" << records[i+(page*(numRow - usedLines))].min;
        cout << endl;
    }
    if (records.size() - page*(numRow - usedLines) < numRow - usedLines) {
        for (int i = 0; i < numRow - (records.size() - page*(numRow - usedLines)) - usedLines; i++)
            cout << string(numCol,' ') <<endl;
    }
}

int viewRecordPage (int numRow, int numCol, vector<record> records, int page) {
    printTopRow(numCol);
    cout << "View Records" << endl;
    cout << "" << endl;
    listRecords(numRow, numCol, records, page);
    cout << "[p] Previous  [n] Next  [s] Sort  [e] Edit  [x] Exit" << endl;
    printBottomRow(numCol);
}

int sortRecordPage(int numRow, int numCol, vector<record> &records, int page) {
    char input = '0';
    string sortParameter = "Amount";
    bool ascend = false;
    while (input != 'x') {
        printTopRow(numCol);
        cout << "Sort Records" << endl;
        cout << "" << endl;        
        listRecords(numRow, numCol, records, page);
        cout << "[t] Toggle Ascend/Descend [1] Amount [2] Type  [3] Account  [4] Date  [5] Amount  [x] Exit" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == '1') {
            sortParameter = "Amount";
        }
        if (input == '2') {
            sortParameter = "Type";
        }
        if (input == '3') {
            sortParameter = "Account";
        }
        if (input == '4') {
            sortParameter = "Date";
        }
        if (input == 't') {
            ascend = !ascend;
        }
        //sortVector(records, sortParameter, ascend);
    }
}

int viewRecordPages(int numRow, int numCol, vector<record> &records) {
    int page = 0;
    while (true) {
        viewRecordPage(numRow, numCol, records, page);
        string input;
        cin >> input;
        if (input == "x") {
            return 0;
        }
        if (input == "p") {
            page--;
            if (page < 0)
                page = 0;
        }
        if (input == "n") {
            page++;
            if (page > (records.size()/(numRow - 8))) {
                page = records.size()/(numRow - 8);
            }
        }
        if (input == "s") {
            sortRecordPage(numRow, numCol, records, page);
        }
        cin.clear();
    }
}