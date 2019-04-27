#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include "stdInterface.h"
#include "viewRecords.h"
#include "filterRecords.h"
using namespace std;

void filteredRecords(int numRow, int numCol, record *&records, int &sizeArray, int &page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int fsizeArray, string query);


// Function: takes in two characters to compare whether they are same
// Inputs: character a, character b
// Outputs: true if same, false if not same
bool stringCompare0(char a, char b) {
    return tolower(a) == tolower(b);
}

// Function: takes in two strings to compare whether they are same
// Inputs: string a, string b
// Outputs: true if same, false if not same
bool stringCompare(string a, string b) {
    if (a.length() == b.length()) {
        return equal(b.begin(), b.end(), a.begin(), stringCompare0);
    }
    else {
        return false;
    }
}

// Function: filters the records data by account keyword
// Inputs: number of rows for interface, number of columns for interface,
//         array of records, size of array of records, page number,
//         used lines in interface, ascending or descending,
//         temperary array of records for filtered records, size of fRecords
// Outputs: updates filtered records
void filterByAccount(int numRow, int numCol, record *&records, int &sizeArray, int &page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int &fsizeArray) {
    printTopRow(numCol);
    cout << "Filter Records";
    cout << endl;
    cout << "Please enter the keyword" << endl;
    cout << endl;
    cout << "Category: Account" << endl << endl;
    cout << "Keyword: ";
    for (int i = 0; i < numRow - 9; i++)
        cout << endl;
    cout << "[x] Cancel" << endl;
    printBottomRow(numCol);
    string search;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, search);
    if (search != "x") {
        for (int i = 0; i < sizeArray; i++) {
            if (stringCompare(records[i].account, search)) {
                updateRecordsSize(fRecords, fsizeArray, 1);
                fRecords[fsizeArray-1] = records[i];
                fRecords[fsizeArray-1].originalIndex = i;
            }
        }
        filteredRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray, search);
    }
}

// Function: filters the records data by type keyword
// Inputs: number of rows for interface, number of columns for interface,
//         array of records, size of array of records, page number,
//         used lines in interface, ascending or descending,
//         temperary array of records for filtered records, size of fRecords
// Outputs: updates filtered records
void filterByType(int numRow, int numCol, record *&records, int &sizeArray, int &page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int &fsizeArray) {
    printTopRow(numCol);
    cout << "Filter Records ";
    cout << endl;
    cout << "Please enter the keyword" << endl;
    cout << endl;
    cout << "Category: Type" << endl << endl;
    cout << "Keyword: ";
    for (int i = 0; i < numRow - 9; i++)
        cout << endl;
    cout << "[x] Cancel" << endl;
    printBottomRow(numCol);
    string search;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, search);
    if (search != "x") {
        for (int i = 0; i < sizeArray; i++) {
            if (stringCompare(records[i].type, search)) {
                updateRecordsSize(fRecords, fsizeArray, 1);
                fRecords[fsizeArray-1] = records[i];
                fRecords[fsizeArray-1].originalIndex = i;
            }
        }
        filteredRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray, search);
    }
}

void filterByDate1(int numRow, int numCol, record *&records, int &sizeArray, int &page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int &fsizeArray, record &dateRecord);

// Function: prints interface for filtering by date (year), gets input for the year variable
// Inputs: number of rows for interface, number of columns for interface,
//         array of records, size of array of records, page number,
//         used lines in interface, ascending or descending,
//         temperary array of records for filtered records, size of fRecords, record to store dates
// Outputs: proceeds to month interface
void filterByDate0(int numRow, int numCol, record *&records, int &sizeArray, int &page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int &fsizeArray) {
    record dateRecord;
    string input;
    bool error = false;
    while (true) {
        printTopRow(numCol);
        cout << "Filter Records" << endl;
        if (error)
            cout << "Error! Please enter a valid input. ";
        cout << "Please enter the year (enter * to skip)" << endl;
        cout << endl;
        cout << "Category: Date" << endl << endl;
        cout << "Year: " << endl;
        cout << "Month: " << endl;
        cout << "Day: " << endl;
        for (int i = 0; i < numRow - 12; i++)
            cout << endl;
        cout << "[x] Cancel" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == "x")
            break;
        if (!isInteger(input) && input != "*")
            error = true;
        else {
            if (input == "*")
                input = "-1";
            dateRecord.year = stoi(input);
            filterByDate1(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray, dateRecord);
            break;
        }
    }
}

void filterByDate2(int numRow, int numCol, record *&records, int &sizeArray, int &page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int &fsizeArray, record &dateRecord);


// Function: prints interface for filtering by date (month), gets input for the month variable
// Inputs: number of rows for interface, number of columns for interface,
//         array of records, size of array of records, page number,
//         used lines in interface, ascending or descending,
//         temperary array of records for filtered records, size of fRecords, record to store dates
// Outputs: proceeds to day interface
void filterByDate1(int numRow, int numCol, record *&records, int &sizeArray, int &page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int &fsizeArray, record &dateRecord) {
    string input;
    bool error = false;
    while (true) {
        printTopRow(numCol);
        cout << "Filter Records" << endl;
        if (error)
            cout << "Error! Please enter a valid input. ";
        cout << "Please enter the month (enter * to skip)" << endl;
        cout << endl;
        cout << "Category: Date" << endl << endl;
        cout << "Year: " << (dateRecord.year == -1 ? "*" : to_string(dateRecord.year)) << endl;
        cout << "Month: " << endl;
        cout << "Day: " << endl;
        for (int i = 0; i < numRow - 12; i++)
            cout << endl;
        cout << "[x] Cancel" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == "x")
            break;
        if (!isInteger(input) && input != "*")
            error = true;
        else {
            if (input == "*")
                input = "-1";
            dateRecord.month = stoi(input);
            filterByDate2(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray, dateRecord);
            break;
        }
    }
}

// Function: checks if dates of the record match one another
// Inputs: two records
// Outputs: true if they the dates are same, false if they are different
bool checkDateMatch (record record1, record record2) {
    if (record1.day != -1 && record1.day != record2.day)
        return false;
    if (record1.month != -1 && record1.month != record2.month)
        return false;
    if (record1.year != -1 && record1.year != record2.year)
        return false;
    return true;
}


// Function: prints interface for filtering by date (day), gets input for the year variable
// Inputs: number of rows for interface, number of columns for interface,
//         array of records, size of array of records, page number,
//         used lines in interface, ascending or descending,
//         temperary array of records for filtered records, size of fRecords, record to store dates
// Outputs: updates filtered records
void filterByDate2(int numRow, int numCol, record *&records, int &sizeArray, int &page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int &fsizeArray, record &dateRecord) {
    string input;
    bool error = false;
    while (true) {
        printTopRow(numCol);
        cout << "Filter Records" << endl;
        if (error)
            cout << "Error! Please enter a valid input. ";
        cout << "Please enter the day (enter * to skip)" << endl;
        cout << endl;
        cout << "Category: Date" << endl << endl;
        cout << "Year: " << (dateRecord.year == -1 ? "*" : to_string(dateRecord.year)) << endl;
        cout << "Month: " << (dateRecord.month == -1 ? "*" : to_string(dateRecord.month)) << endl;
        cout << "Day: " << endl;
        for (int i = 0; i < numRow - 12; i++)
            cout << endl;
        cout << "[x] Cancel" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == "x")
            break;
        if (!isInteger(input) && input != "*")
            error = true;
        else {
            if (input == "*")
                input = "-1";
            dateRecord.day = stoi(input);
            for (int i = 0; i < sizeArray; i++) {
                if (checkDateMatch(dateRecord, records[i])) {
                    updateRecordsSize(fRecords, fsizeArray, 1);
                    fRecords[fsizeArray-1] = records[i];
                    fRecords[fsizeArray-1].originalIndex = i;
                }
            }
            
            string search = (dateRecord.day == -1 ? "*" : to_string(dateRecord.day)) + "/" + (dateRecord.month == -1 ? "*" : to_string(dateRecord.month)) + "/" + (dateRecord.year == -1 ? "*" : to_string(dateRecord.year));
            filteredRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray, search);
            break;
        }
    }
}

// Function: creates a temperary record array to store the filtered records and calls functions based on category
// Inputs: number of rows for interface, number of columns for interface,
//         array of records, size of array of records, page number,
//         used lines in interface, sorting parameter, ascending or descending,
//         character of category
// Outputs: filters by category
void filterRecords(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string &sortParameter, bool &ascend, char category) {
    int fsizeArray = 0;
    record * fRecords = new record[fsizeArray];
    // filter by type
    if (category == '1')
        filterByType(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray);
    // filter by account
    if (category == '2')
        filterByAccount(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray);
    // filter by date
    if (category == '3') {
        filterByDate0(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray);
    }
    delete[] fRecords;
}

// Function: prints out the filter records interface and shows sort and edit functions
// Inputs: number of rows for interface, number of columns for interface,
//         array of records, size of array of records, page number,
//         used lines in interface, sorting parameter, ascending or descending,
//         temperary filtered record array, size of filtered array, string of filtered category
// Outputs: interface of filtered data
void filteredRecords(int numRow, int numCol, record *&records, int &sizeArray, int &page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int fsizeArray, string query) {
    while (true) {
        printTopRow(numCol);
        cout << "Filter Records (Page " << page + 1 << " of " << ceilDivision(fsizeArray,numRow - usedLines) << ") ";
        printSortingBy(sortParameter, ascend);
        cout << " (Keyword: " << query << ")" << endl;
        cout << "Please enter [s] to sort or [e] to edit" << endl;
        cout << endl;
        listRecords(numRow, numCol, fRecords, fsizeArray, page, usedLines);
        cout << endl;
        cout << "[p] Previous [n] Next [s] Sort [e] Edit [x] Exit" << endl;
        printBottomRow(numCol);
        string input;
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
        if (input == "s") {
            sortRecordPage(numRow, numCol, fRecords, fsizeArray, page, usedLines, sortParameter, ascend);
        }
        if (input == "e") {
            editFilteredRecordPage(numRow, numCol, fRecords, fsizeArray, page, usedLines, sortParameter, ascend, records, sizeArray);
        }
    }
}
