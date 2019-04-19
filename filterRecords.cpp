#include <iostream>
#include <string>
#include <limits>
#include "stdInterface.h"
#include "viewRecords.h"
#include "filterRecords.h"
using namespace std;

string filterByAccount(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string &sortParameter, bool ascend, record *&fRecords, int &fsizeArray) {
    printTopRow(numCol);
    cout << "Filter by Account ";
    cout << endl;
    cout << ' ' << endl;
    cout << "Please enter a keyword to filter by the keyword" << endl;
    printBottomRow(numCol);
    string search;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, search);
    for (int i = 0; i < sizeArray; i++) {
        if (records[i].account == search) {
            updateRecordsSize(fRecords, fsizeArray, 1);
            fRecords[fsizeArray-1] = records[i];
            fRecords[fsizeArray-1].originalIndex = i;
        }
    }
    return search;
}

string filterByType(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string &sortParameter, bool ascend, record *&fRecords, int &fsizeArray) {
    printTopRow(numCol);
    cout << "Filter by Type ";
    printSortingBy(sortParameter, ascend);
    cout << endl;
    cout << ' ' << endl;
    cout << "Please enter a keyword to filter by the keyword" << endl;
    printBottomRow(numCol);
    string search;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, search);
    for (int i = 0; i < sizeArray; i++) {
        if (records[i].type == search) {
            updateRecordsSize(fRecords, fsizeArray, 1);
            fRecords[fsizeArray-1] = records[i];
            fRecords[fsizeArray-1].originalIndex = i;
        }
    }
    return search;
}


void filterByDate(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string &sortParameter, bool ascend, record *&fRecords, int &fsizeArray) {
    /*printTopRow(numCol);
    cout << "Filter by Type";
    cout << endl;
    cout << "Please enter a keyword to filter by the keyword" << endl;
    cout << "" << endl;
    string search;
    cin >> search;
    for (int i = 0; i < sizeArray; i++) {
        if (records[i].type == search) {
            updateRecordsSize(fRecords, fsizeArray, 1);
            fRecords[fsizeArray-1] = records[i];
            fRecords[fsizeArray-1].originalIndex = i;
        }
    }*/
    cout << "filter by date not completed" << endl;
}

void filteredRecords(int numRow, int numCol, record *records, int &sizeArray, int page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int fsizeArray, string query);

void filterRecords(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string &sortParameter, bool ascend, char category) {
    int fsizeArray = 0;
    record * fRecords = new record[fsizeArray];
    // filter by type
    if (category == '1') {
        string query = filterByType(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray);
        filteredRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray, query);
    }
    // filter by account
    if (category == '2') {
        string query = filterByAccount(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray);
        filteredRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray, query);
    }
    // filter by date
    if (category == '3') {
        filterByDate(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray);
        //filteredRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, fRecords, fsizeArray, query);
    }
}

void filteredRecords(int numRow, int numCol, record *records, int &sizeArray, int page, int usedLines, string &sortParameter, bool &ascend, record *&fRecords, int fsizeArray, string query) {
    while (true) {
        printTopRow(numCol);
        cout << "Filter Records (Page " << page + 1 << " of " << ceilDivision(fsizeArray,numRow - usedLines) << ")";
        cout << " (Query: " << query << ")" << endl;
        printSortingBy(sortParameter, ascend);
        cout << endl;
        cout << "Please enter [s] to sort or [e] to edit" << endl;
        cout << endl;
        listRecords(numRow, numCol, fRecords, fsizeArray, page, usedLines);
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
            cout << "sort not yet implmented" << endl;
        }
        if (input == "e") {
            cout << "edit not yet implmented" << endl;
        }
    }
}
