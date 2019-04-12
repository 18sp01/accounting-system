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
int printVector(int numRow, int numCol, vector<record> records) {
    int linesOfText;
    if (records.size() + 5 < numRow - 3)
        linesOfText = records.size() + 5;
    else
        linesOfText = numRow - 3;
    printTopRow(numCol);
    cout << convertStringtoLine("View Records",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    int page = 0;
    while (true) {
        if (records.size() < numRow - 8) {
            for (int i = 0; i < records.size(); i++) {
                cout << " " << i+1 << " | ";
                cout << "Amount: " << records[i].amount << " | ";
                cout << "Type: " << records[i].type << " | ";
                cout << "Account: " << records[i].account << " | ";
                cout << "Date: " << records[i].day << " " << records[i].month << " " << records[i].year << " " << records[i].hour << ":" << records[i].min;
                cout << endl;
            }
        }
        else {
            for (int i = 0; i < numRow - 7; i++) {
                cout << " " << i+1 << " | ";
                cout << "Amount: " << records[i].amount << " | ";
                cout << "Type: " << records[i].type << " | ";
                cout << "Account: " << records[i].account << " | ";
                cout << "Date: " << records[i].day << " " << records[i].month << " " << records[i].year << " " << records[i].hour << ":" << records[i].min;
                cout << endl;
            }
        }
        for (int i = 0; i < numRow - 3 - linesOfText; i++)
            cout << " " << string(numCol,' ') << " " << endl;
        cout << convertStringtoLine("[p] Previous Page",numCol) << endl;
        cout << convertStringtoLine("[n] Next Page",numCol) << endl;
        cout << convertStringtoLine("[x] Exit",numCol) << endl;
        printBottomRow(numCol);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string input;
        getline(cin,input);
        if (input == "x") {
            return 0;
        }
        else {
            return 1;
        }
    }
}