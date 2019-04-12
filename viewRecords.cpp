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
int printPage(int numRow, int numCol, vector<record> records, int &page) {
    printTopRow(numCol);
    cout << convertStringtoLine("View Records",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    if (records.size() - page*(numRow - 8) < numRow - 8) {
        for (int i = 0; i < records.size() - page*(numRow - 8); i++) {
            cout << " " << i+(page*(numRow - 8))+1 << " | ";
            cout << "Amount: " << records[i+(page*(numRow - 8))].amount << " | ";
            cout << "Type: " << records[i+(page*(numRow - 8))].type << " | ";
            cout << "Account: " << records[i+(page*(numRow - 8))].account << " | ";
            cout << "Date: " << records[i+(page*(numRow - 8))].day << " " << records[i+(page*(numRow - 8))].month << " " << records[i+(page*(numRow - 8))].year << " " << records[i+(page*(numRow - 8))].hour << ":" << records[i+(page*(numRow - 8))].min;
            cout << endl;
        }            
        for (int i = 0; i < numRow - (records.size() - page*(numRow - 8)) - 8; i++)
            cout << string(numCol,' ') <<endl;
    }
    else {
        for (int i = 0; i < numRow - 8; i++) {
            cout << " " << i+1 << " | ";
            cout << "Amount: " << records[i+(page*(numRow - 8))].amount << " | ";
            cout << "Type: " << records[i+(page*(numRow - 8))].type << " | ";
            cout << "Account: " << records[i+(page*(numRow - 8))].account << " | ";
            cout << "Date: " << records[i+(page*(numRow - 8))].day << " " << records[i+(page*(numRow - 8))].month << " " << records[i+(page*(numRow - 8))].year << " " << records[i+(page*(numRow - 8))].hour << ":" << records[i+(page*(numRow - 8))].min;
            cout << endl;
        }
    }
    cout << convertStringtoLine("[p] Previous Page",numCol) << endl;
    cout << convertStringtoLine("[n] Next Page",numCol) << endl;
    cout << convertStringtoLine("[x] Exit",numCol) << endl;
    printBottomRow(numCol);
}

int printPages(int numRow, int numCol, vector<record> records) {
    int page = 0;
    while (true) {
        printPage(numRow, numCol, records, page);
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
        cin.clear();
    }
}