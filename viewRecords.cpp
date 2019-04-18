#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
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

int ceilDivision(int number, int divisor) {
    return (number + divisor - 1) / divisor;
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

void printCategories() {
    cout << setw(5) << left << '#' << " | ";
    cout << setw(15) << left << "Amount" << " | ";
    cout << setw(22) << left << "Type" << " | ";
    cout << setw(22) << left << "Account"  << " | ";
    cout << "Date";
}

void printRecord(record *records, int index) {
    cout << setw(5) << left << index+1 << " | ";
    cout << setw(15) << records[index].amount << " | ";
    cout << setw(22) << records[index].type << " | ";
    cout << setw(22) << records[index].account << " | ";
    cout << setfill('0') << right << setw(2) << records[index].day << '/' << setw(2) << records[index].month << '/' << records[index].year << " " << setw(2) << records[index].hour << ":" << setw(2) << records[index].min;
    cout << setfill(' ') << endl;
}

void listRecords(int numRow, int numCol, record *records, int sizeArray, int page, int usedLines) {
    int maxI;
    if (sizeArray - page*(numRow - usedLines) < numRow - usedLines)
        maxI = sizeArray - page*(numRow - usedLines);
    else
        maxI = numRow - usedLines;
    printCategories();
    cout << endl;
    for (int i = 0; i < maxI; i++)
        printRecord(records, i+(page*(numRow - usedLines)));
    if (sizeArray - page*(numRow - usedLines) < numRow - usedLines) {
        for (int i = 0; i < numRow - (sizeArray - page*(numRow - usedLines)) - usedLines; i++)
            cout << string(numCol,' ') <<endl;
    }
}

void viewRecordPage (int numRow, int numCol, record *records, int &sizeArray, int page, int usedLines, string sortParameter, bool ascend) {
    printTopRow(numCol);
    cout << "View Records (Page "<< page + 1 << " of " << ceilDivision(sizeArray,numRow - usedLines) << ") ";
    printSortingBy(sortParameter, ascend);
    cout << endl;
    cout << "Please enter [s] to sort records, or [e] to edit records" << endl;
    cout << endl;
    listRecords(numRow, numCol, records, sizeArray, page, usedLines);
    cout << "[p] Previous  [n] Next  [s] Sort  [e] Edit  [x] Exit" << endl;
    printBottomRow(numCol);
}

void sortRecordPage(int numRow, int numCol, record *records, int &sizeArray, int page, int usedLines, string &sortParameter, bool &ascend) {
    char input = '0';
    while (input != 'x') {
        printTopRow(numCol);
        cout << "Sort Records (Page "<< page + 1 << " of " << ceilDivision(sizeArray,numRow - usedLines) << ") ";
        printSortingBy(sortParameter, ascend);
        cout << endl;
        cout << "Please enter [1], [2], [3], or [4] to sort by the corresponding category" << endl;
        cout << "" << endl;
        listRecords(numRow, numCol, records, sizeArray, page, usedLines);
        cout << "[p] Previous [n] Next [t] Toggle Ascend/Descend [1] Amount [2] Type [3] Account [4] Date [x] Exit" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == 'p') {
            page--;
            if (page < 0)
                page = 0;
        }
        if (input == 'n') {
            page++;
            if (page > ceilDivision(sizeArray,numRow - usedLines) - 1)
                page = ceilDivision(sizeArray,numRow - usedLines) - 1;
        }
        if (input == '1') {
            sortParameter = "Amount";
            ascend = false;
            sortByAmount (records, sizeArray, ascend);   
        }
        if (input == '2') {
            sortParameter = "Type";
            ascend = true;
            sortByType (records, sizeArray, ascend);
        }
        if (input == '3') {
            sortParameter = "Account";
            ascend = true;
            sortByAccount (records, sizeArray, ascend);
        }
        if (input == '4') {
            sortParameter = "Date";
            ascend = false;
            sortByDate (records, sizeArray, ascend);
        }
        if (input == 't') {
            ascend = !ascend;
            reverseVector(records, sizeArray);
        }
    }
}

void editRecordPage(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string sortParameter, bool ascend) {
    printTopRow(numCol);
    cout << "Edit Records (Page "<< page + 1 << " of " << sizeArray/(numRow - usedLines) + 1 << ") ";
    printSortingBy(sortParameter, ascend);
    cout << endl;
    cout << "Please enter the number corresponding to the record you want to edit" << endl;
    cout << endl;
    listRecords(numRow, numCol, records, sizeArray, page, usedLines);
    cout << "[x] Cancel" << endl;
    printBottomRow(numCol);
    
    string input;
    cin >> input;
    while (input != "x") {            
        int x = stoi(input);
        if (x > 0 && x < sizeArray + 1) {
            editRecord(numRow, numCol, records, sizeArray, x);
            break;
        }
        cin >> input;
    }
}

int viewRecordPages(int numRow, int numCol, int &sizeArray, record *&records) {
    int page = 0;
    int usedLines = 8;
    string sortParameter = "Date";
    bool ascend = false;
    sortByDate (records, sizeArray, ascend);
    while (true) {
        viewRecordPage(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend);
        string input;
        cin >> input;
        if (input == "x")
            return 0;
        if (input == "p") {
            page--;
            if (page < 0)
                page = 0;
        }
        if (input == "n") {
            page++;
            if (page > ceilDivision(sizeArray,numRow - usedLines) - 1)
                page = ceilDivision(sizeArray,numRow - usedLines) - 1;
        }
        if (input == "e")
            editRecordPage(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend);
        if (input == "s")
            sortRecordPage(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend);
    }
}