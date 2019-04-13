#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "stdInterface.h"
#include "addRecord.h"
#include "viewRecords.h"
#include "editRecords.h"
#include "sortRecords.h"
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
    int usedLines = 7;
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

void printSortingBy (string sortParameter, bool ascend) {
    cout << "(Sorting by ";
    if (sortParameter != "Date")
        cout << sortParameter << " ";
    if (sortParameter == "Account" || sortParameter == "Type")
        cout << "Alphabetically ";
    if (sortParameter == "Date") {
        if (ascend)
            cout << "Least Recent)";
        else
            cout << "Most Recent)";
    }
    else {
        if (ascend)
            cout << "in Ascending Order)";
        else
            cout << "in Descending Order)";
    }
}

int viewRecordPage (int numRow, int numCol, vector<record> records, int page, string sortParameter, bool ascend) {
    printTopRow(numCol);
    cout << "View Records (Page "<< page + 1 << " of " << records.size()/(numRow - 7) + 1 << ") ";
    printSortingBy(sortParameter, ascend);
    cout << endl;
    cout << "Please enter [s] to sort records, or [e] to edit records" << endl;
    cout << "" << endl;
    listRecords(numRow, numCol, records, page);
    cout << "[p] Previous  [n] Next  [s] Sort  [e] Edit  [x] Exit" << endl;
    printBottomRow(numCol);
}

int sortRecordPage(int numRow, int numCol, vector<record> &records, int page, string &sortParameter, bool &ascend) {
    char input = '0';
    while (input != 'x') {
        printTopRow(numCol);
        cout << "Sort Records (Page "<< page + 1 << " of " << records.size()/(numRow - 7) + 1 << ") ";
        printSortingBy(sortParameter, ascend);
        cout << endl;
        cout << "Please enter [1], [2], [3], or [4] to sort by the corresponding category" << endl;
        cout << "" << endl;
        listRecords(numRow, numCol, records, page);
        cout << "[t] Toggle Ascend/Descend [1] Amount [2] Type  [3] Account  [4] Date  [x] Exit" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == '1') {
            sortParameter = "Amount";
            ascend = false;
            sortByAmount (records, ascend);   
        }
        if (input == '2') {
            sortParameter = "Type";
            ascend = true;
            sortByType (records, ascend);
        }
        if (input == '3') {
            sortParameter = "Account";
            ascend = true;
            sortByAccount (records, ascend);
        }
        if (input == '4') {
            sortParameter = "Date";
            ascend = false;
            sortByDate (records, ascend);
        }
        if (input == 't') {
            ascend = !ascend;
            reverseVector(records);
        }
    }
}

int editRecordPage(int numRow, int numCol, vector<record> &records, int page, string sortParameter, bool ascend) {
    char input;
    while (input != 'x') {
        printTopRow(numCol);
        cout << "Edit Records (Page "<< page + 1 << " of " << records.size()/(numRow - 7) + 1 << ") ";
        printSortingBy(sortParameter, ascend);
        cout << endl;
        cout << "Enter the number of the data you want to edit" << endl;
        cout << "" << endl;
        listRecords(numRow, numCol, records, page);
        cout << "[x] Cancel" << endl;
        printBottomRow(numCol);
        cin >> input;
        int x;
        while (input != 'x') {            
            x = (int)input - 48;
            if (x > 0 && x < records.size())
                editRecord (numRow, numCol, records, x);
                break;
            cin >> input;
        }
        break;
    }
}

int viewRecordPages(int numRow, int numCol, vector<record> &records) {
    int page = 0;
    string sortParameter = "Date";
    bool ascend = false;
    sortByDate (records, ascend);
    while (true) {
        viewRecordPage(numRow, numCol, records, page, sortParameter, ascend);
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
            if (page > (records.size()/(numRow - 7))) {
                page = records.size()/(numRow - 7);
            }
        }
        if (input == "e") {
            editRecordPage(numRow, numCol, records, page, sortParameter, ascend);
        }
        if (input == "s") {
            sortRecordPage(numRow, numCol, records, page, sortParameter, ascend);
        }
        cin.clear();
    }
}