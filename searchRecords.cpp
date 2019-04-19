#include <iostream>
#include <string>
#include <limits>
#include "stdInterface.h"
#include "viewRecords.h"
#include "searchRecords.h"
using namespace std;

string searchByAccount(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string &sortParameter, bool ascend, record *&sRecords, int &searchSizeArray) {
    printTopRow(numCol);
    cout << "Search by Account ";
    cout << endl;
    cout << ' ' << endl;
    cout << "Please enter the search query" << endl;
    printBottomRow(numCol);
    string search;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, search);
    for (int i = 0; i < sizeArray; i++) {
        if (records[i].account == search) {
            updateRecordsSize(sRecords, searchSizeArray, 1);
            sRecords[searchSizeArray-1] = records[i];
            sRecords[searchSizeArray-1].originalIndex = i;
        }
    }
    return search;
}

string searchByType(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string &sortParameter, bool ascend, record *&sRecords, int &searchSizeArray) {
    printTopRow(numCol);
    cout << "Search by Type ";
    printSortingBy(sortParameter, ascend);
    cout << endl;
    cout << ' ' << endl;
    cout << "Please enter the search query" << endl;
    listRecords(numRow, numCol, records, sizeArray, page, usedLines);
    cout << endl << "[x] Cancel" << endl;
    printBottomRow(numCol);
    string search;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, search);
    for (int i = 0; i < sizeArray; i++) {
        if (records[i].type == search) {
            updateRecordsSize(sRecords, searchSizeArray, 1);
            sRecords[searchSizeArray-1] = records[i];
            sRecords[searchSizeArray-1].originalIndex = i;
        }
    }
    return search;
}


void searchByDate(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string &sortParameter, bool ascend, record *&sRecords, int &searchSizeArray) {
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
    cout << "search by date not completed" << endl;
}

void searchedRecords(int numRow, int numCol, record *records, int &sizeArray, int page, int usedLines, string &sortParameter, bool &ascend, record *&sRecords, int searchSizeArray, string query);

void searchRecords(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string &sortParameter, bool ascend, char category) {
    int searchSizeArray = 0;
    record * sRecords = new record[searchSizeArray];
    // search by type
    if (category == '1') {
        string query = searchByType(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, sRecords, searchSizeArray);
        searchedRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, sRecords, searchSizeArray, query);
    }
    // search by account
    if (category == '2') {
        string query = searchByAccount(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, sRecords, searchSizeArray);
        searchedRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, sRecords, searchSizeArray, query);
    }
    // search by date
    if (category == '3') {
        searchByDate(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, sRecords, searchSizeArray);
        //searchRecords(numRow, numCol, records, sizeArray, page, usedLines, sortParameter, ascend, sRecords, sSizeArray, query);
    }
}

void searchedRecords(int numRow, int numCol, record *records, int &sizeArray, int page, int usedLines, string &sortParameter, bool &ascend, record *&sRecords, int searchSizeArray, string query) {
    while (true) {
        printTopRow(numCol);
        cout << "Search Records (Page " << page + 1 << " of " << ceilDivision(searchSizeArray,numRow - usedLines) << ")";
        cout << " (Query: " << query << ")" << endl;
        printSortingBy(sortParameter, ascend);
        cout << endl;
        cout << "Please enter [s] to sort or [e] to edit" << endl;
        cout << endl;
        listRecords(numRow, numCol, sRecords, searchSizeArray, page, usedLines);
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
            if (page > ceilDivision(searchSizeArray,numRow - usedLines) - 1)
                page = ceilDivision(searchSizeArray,numRow - usedLines) - 1;
        }
        if (input == "s") {
            cout << "sort not yet implmented" << endl;
        }
        if (input == "e") {
            cout << "edit not yet implmented" << endl;
        }
    }
}
