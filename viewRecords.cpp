#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <iomanip>
#include "stdInterface.h"
#include "addRecord.h"
#include "viewRecords.h"
#include "editRecords.h"
#include "sortRecords.h"
#include "filterRecords.h"
using namespace std;

// Function: ceilDivision: a functions that returns the ceil division of two numbers
// Inputs: a number and its divisor
// Outputs: the ceil division of the two numbers
int ceilDivision(int number, int divisor) {
    return (number + divisor - 1) / divisor;
}

// Function: isInteger: a functions check whether a number is a positive integer
// Inputs: a string with a potential integer
// Outputs: true if the string is a positive integer, false if otherwise
bool isInteger(string s) {
    string temp = s;
    for (char i : temp) {
        if (!isdigit(i))
            return false;
    }
    return true;
}

// Function: printSortingBy: prints a string "(Sorted by...)" depending on sort parameter and bool ascend
// Inputs: a string containing the sortParameter, and bool indicating whether it is sorting by ascend or descending order
// Outputs: outputs a string to iostream
void printSortingBy (string sortParameter, bool ascend) {
    cout << "(Sorted by ";
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

// Function: printCategories: prints the first line of the view records list
// Inputs: none
// Outputs: outputs a string to iostream
void printCategories() {
    cout << setw(5) << left << '#' << " | ";
    cout << setw(15) << left << "Amount" << " | ";
    cout << setw(22) << left << "Type" << " | ";
    cout << setw(22) << left << "Account"  << " | ";
    cout << "Date";
}

// Function: printRecord: prints the details of the record corresponding to the input index
// Inputs: dynamic array records, index corresponding to the record to display
// Outputs: outputs a string to iostream
void printRecord(record *records, int index) {
    cout << setw(5) << left << index+1 << " | ";
    cout << setw(15) << records[index].amount << " | ";
    cout << setw(22) << records[index].type << " | ";
    cout << setw(22) << records[index].account << " | ";
    cout << setfill('0') << right << setw(2) << records[index].day << '/' << setw(2) << records[index].month << '/' << records[index].year << " " << setw(2) << records[index].hour << ":" << setw(2) << records[index].min;
    cout << setfill(' ') << endl;
}

// Function: listRecords: prints out a list of records depending on the page and used line
// Inputs: dynamic array records, size of the array, the page the user is currently on, integer of number of used lines
// Outputs: outputs multiple lines to iostream
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
            cout << endl;
    }
}

// Function: viewRecordPage: prints out a view records page
// Inputs: dynamic array records, size of the array, the page the user is currently on, integer of number of used lines, information regarding the user's sorting mode
// Outputs: output the page of records to the iostream
void viewRecordPage (int numRow, int numCol, record *records, int sizeArray, int page, int usedLines, string sortParameter, bool ascend) {
    printTopRow(numCol);
    cout << "View Records (Page "<< page + 1 << " of " << ceilDivision(sizeArray,numRow - usedLines) << ") ";
    printSortingBy(sortParameter, ascend);
    cout << endl;
    cout << "Please enter [s] to sort records, [e] to edit records, [f] to filter/search records" << endl;
    cout << endl;
    listRecords(numRow, numCol, records, sizeArray, page, usedLines);
    cout << endl;
    cout << "[p] Previous  [n] Next  [s] Sort  [e] Edit  [f] Filter  [x] Exit" << endl;
    printBottomRow(numCol);
}

// Function: sortRecordPage: prints out a sort records page
// Inputs: dynamic array records, size of the array, the page the user is currently on, integer of number of used lines, reference to information regarding the user's sorting mode
// Outputs: output the page of records to be sorted to the iostream
void sortRecordPage(int numRow, int numCol, record *records, int sizeArray, int &page, int usedLines, string &sortParameter, bool &ascend) {
    char input;
    while (true) {
        printTopRow(numCol);
        cout << "Sort Records (Page "<< page + 1 << " of " << ceilDivision(sizeArray,numRow - usedLines) << ") ";
        printSortingBy(sortParameter, ascend);
        cout << endl;
        cout << "Please enter [1], [2], [3], or [4] to sort by the corresponding category" << endl;
        cout << endl;
        listRecords(numRow, numCol, records, sizeArray, page, usedLines);
        cout << endl;
        cout << "[p] Previous [n] Next [t] Toggle Ascend/Descend [1] Amount [2] Type [3] Account [4] Date [x] Exit" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == 'x')
            break;
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
            reverseArray(records, sizeArray);
        }
    }
}

// Function: editRecordPage: prints out a sort records page
// Inputs: reference to dynamic array records and size of the array,reference to the page the user is currently on, integer of number of used lines, reference to information regarding the user's sorting mode
// Outputs: output the page of records to be sorted to the iostream
void editRecordPage(int numRow, int numCol, record *&records, int &sizeArray, int &page, int usedLines, string sortParameter, bool ascend) {
    string input;
    while (true) {
        if (page > ceilDivision(sizeArray,numRow - usedLines) - 1)
            page = ceilDivision(sizeArray,numRow - usedLines) - 1;
        printTopRow(numCol);
        cout << "Edit Records (Page "<< page + 1 << " of " << sizeArray/(numRow - usedLines) + 1 << ") ";
        printSortingBy(sortParameter, ascend);
        cout << endl;
        cout << "Please enter the number corresponding to the record you want to edit" << endl;
        cout << endl;
        listRecords(numRow, numCol, records, sizeArray, page, usedLines);
        cout << endl;
        cout << "[p] Previous  [n] Next  [x] Cancel" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == "x")
            break;
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
        if (isInteger(input)) {
            int x = stoi(input);
            if (x > 0 && x < sizeArray + 1) {
                editRecord(numRow, numCol, records, sizeArray, x);
                if (page > ceilDivision(sizeArray,numRow - usedLines) - 1)
                    page = ceilDivision(sizeArray,numRow - usedLines) - 1;
                break;
            }
        }
    }
}

// Function: editFilteredRecordPage: prints out a filtered sort records page
// Inputs: reference to dynamic array records and size of the array, reference to dynamic array of filtered records and size of the array, reference to the page the user is currently on, integer of number of used lines, reference to information regarding the user's sorting mode
// Outputs: output the page of filtered records to be edited to the iostream
void editFilteredRecordPage(int numRow, int numCol, record *&fRecords, int &fsizeArray, int &page, int usedLines, string sortParameter, bool ascend, record *&records, int &sizeArray) {
    string input;
    while (true) {
        printTopRow(numCol);
        cout << "Edit Records (Page "<< page + 1 << " of " << fsizeArray/(numRow - usedLines) + 1 << ") ";
        printSortingBy(sortParameter, ascend);
        cout << endl;
        cout << "Please enter the number corresponding to the record you want to edit" << endl;
        cout << endl;
        listRecords(numRow, numCol, fRecords, fsizeArray, page, usedLines);
        cout << endl;
        cout << "[p] Previous  [n] Next  [x] Cancel" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == "x")
            break;
        if (input == "p") {
            page--;
            if (page < 0)
                page = 0;
        }
        if (input == "n") {
            page++;
            if (page > ceilDivision(fsizeArray,numRow - usedLines) - 1)
                page = ceilDivision(fsizeArray,numRow - usedLines) - 1;
        }
        if (isInteger(input)) {
            int x = stoi(input);
            if (x > 0 && x < fsizeArray + 1) {
                editfRecord(numRow, numCol, fRecords, fsizeArray, x, records, sizeArray);
                if (page > ceilDivision(fsizeArray,numRow - usedLines) - 1)
                    page = ceilDivision(fsizeArray,numRow - usedLines) - 1;
                break;
            }
        }
    }
}

// Function: filterRecordsPage: print out interface that guides the user to filter their records
// Inputs: reference to dynamic array records and size of the array, integer of number of used lines, reference to information regarding the user's sorting mode
// Outputs: interface that guides the user to filter their records
void filterRecordsPage(int numRow, int numCol, record *&records, int &sizeArray, int usedLines, string sortParameter, bool ascend) {
    int page = 0;
    sortParameter = "Date";
    ascend = false;
    char input;
    while (true) {
        printTopRow(numCol);
        cout << "Filter Records";
        cout << endl;
        cout << "Please enter [1], [2], or [3] to filter by the corresponding category" << endl;
        cout << "" << endl;
        cout << "Category: ";
        for (int i = 0; i < numRow - 7; i++)
            cout << endl;
        cout << "[1] Type  [2] Account  [3] Date  [x] Cancel" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == 'x')
            break;
        if (input == '1') {
            filterRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, input);
            break;
        }
        // filter by account
        if (input == '2') {
            filterRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, input);
            break;
        }
        // filter by date
        if (input == '3') {
            filterRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, input);
            break;
        }
    }
}

// Function: viewRecordPages: the main interface that shows the user's records
// Inputs: reference to dynamic array records and size of the array, user input
// Outputs: the interface with the users records
int viewRecordPages(int numRow, int numCol, int &sizeArray, record *&records) {
    int page = 0;
    int usedLines = 9;
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
        if (input == "f")
            filterRecordsPage(numRow, numCol, records, sizeArray, usedLines, sortParameter, ascend);
        if (input == "e")
            editRecordPage(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend);
        if (input == "s")
            sortRecordPage(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend);
    }
}