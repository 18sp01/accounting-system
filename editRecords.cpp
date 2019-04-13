#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
#include <iomanip>
#include "stdInterface.h"
#include "editRecords.h"
using namespace std;

// removeRecord: remove record from records
// Inputs: vector<record> &records: vector of records
//         int index: index of record to be removed
// Outputs: 
void removeRecord (vector<record> &records, int index) {
    records.erase(records.begin() + index);//
}

int editRecord1 (int numRow, int numCol, vector<record> &records, int index, string category);

int editRecord0 (int numRow, int numCol, vector<record> &records, int index) {
    printTopRow(numCol);
    int linesOfText = 5;
    cout << "Edit Record" << endl;
    cout << "Please enter the type of data you want to edit " << endl;
    cout << "" << endl;
    cout << " " << index << " | ";
    cout << "Amount: " << records[index-1].amount << " | ";
    cout << "Type: " << records[index-1].type << " | ";
    cout << "Account: " << records[index-1].account << " | ";
    cout << "Date: " << records[index-1].day << " " << records[index-1].month << " " << records[index-1].year << " " << records[index-1].hour << ":" << records[index-1].min;
    cout << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    cout << "[x] Cancel" << endl;
    printBottomRow(numCol);
    string input;
    cin >> input;
    if (input == "x")
        return 0;
    else if (input == "Type" || input == "Account" || input == "Amount")
        return editRecord1(numRow,numCol,records,index,input);
    else editRecord0 (numRow, numCol, records, index);
}

int editRecord1 (int numRow, int numCol, vector<record> &records, int index, string category) {
    printTopRow(numCol);
    int linesOfText = 5;
    cout << "Edit Record" << endl;
    cout << "Please enter the " << category << endl;
    cout << "" << endl;
    cout << " " << index << " | ";
    cout << "Amount: " << records[index-1].amount << " | ";
    cout << "Type: " << records[index-1].type << " | ";
    cout << "Account: " << records[index-1].account << " | ";
    cout << "Date: " << records[index-1].day << " " << records[index-1].month << " " << records[index-1].year << " " << records[index-1].hour << ":" << records[index-1].min;
    cout << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    cout << "[x] Cancel" << endl;
    printBottomRow(numCol);
    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, input);
    if (input == "x")
        return 0;
    else {
        if (category == "Type") {
            records[index-1].type = input;
            return 1;
        }
        if (category == "Amount") {
            records[index-1].amount = stod(input);
            return 1;
        }
        if (category == "Account") {
            records[index-1].account = input;
            return 1;
        }
        else
            editRecord1(numRow,numCol,records,index,input);
    }
}

int editRecord2 (int numRow, int numCol, vector<record> &records, int index) {
    printTopRow(numCol);
    int linesOfText = 5;
    cout << "Edit Record" << endl;
    cout << "Record Saved! Enter [x] to exit." << endl;
    cout << "" << endl;
    cout << " " << index << " | ";
    cout << "Amount: " << records[index-1].amount << " | ";
    cout << "Type: " << records[index-1].type << " | ";
    cout << "Account: " << records[index-1].account << " | ";
    cout << "Date: " << records[index-1].day << " " << records[index-1].month << " " << records[index-1].year << " " << records[index-1].hour << ":" << records[index-1].min;
    cout << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    cout << "[x] Exit" << endl;
    printBottomRow(numCol);
    char input;
    cin >> input;
    while (input != 'x') {
        cin >> input;
    }
    return 0;
}

void editRecord (int numRow, int numCol, vector<record> &records, int index) {
    if (editRecord0(numRow, numCol, records, index)) {
        editRecord2(numRow, numCol, records, index);
    }
}