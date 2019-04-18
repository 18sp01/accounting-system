#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <iomanip>
#include "stdInterface.h"
#include "addRecord.h"
#include "editRecords.h"
using namespace std;

// removeRecord: remove record from records
// Inputs: vector<record> &records: vector of records
//         int index: index of record to be removed
// Outputs: 
//void removeRecord (vector<record> &records, int index) {
   // records.erase(records.begin() + index);//
//}

void deleteRecord(record *&records, int &sizeArray, int index) {
    record *newRecords = new record[sizeArray-1];
    bool shifted = false;
    int j = 0;
    for (int i = 0; i < sizeArray-1; i++) {
        cout << i << endl;
        newRecords[i] = records[j];
        if (i == index-1 && !shifted) {
            shifted = true;
            i--;
        }
        j++;
    }
    sizeArray -= 1;
    delete [] records;
    records = newRecords;
}

int editRecord1 (int numRow, int numCol, record *records, int index, string category, bool error);

int editRecord0 (int numRow, int numCol, record *&records, int &sizeArray, int index) {
    printTopRow(numCol);
    int linesOfText = 5;
    cout << "Edit Record" << endl;
    cout << "Please enter [1], [2] or [3] to edit the corresponding data, or enter [d] to delete the record" << endl;
    cout << "" << endl;
    cout << " " << index << " | ";
    cout << "Amount: " << records[index-1].amount << " | ";
    cout << "Type: " << records[index-1].type << " | ";
    cout << "Account: " << records[index-1].account << " | ";
    cout << "Date: " << records[index-1].day << " " << records[index-1].month << " " << records[index-1].year << " " << records[index-1].hour << ":" << records[index-1].min;
    cout << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    cout << "[1] Amount  [2] Type  [3] Account  [d] Delete  [x] Cancel" << endl;
    printBottomRow(numCol);
    char input;
    cin >> input;
    if (input == 'x')
        return 0;
    if (input == 'd')
    
        deleteRecord(records, sizeArray, index);
        return 0;
    if (input == '1')
        return editRecord1(numRow,numCol,records,index,"amount",false);
    if (input == '2')
        return editRecord1(numRow,numCol,records,index,"type",false);
    if (input == '3')
        return editRecord1(numRow,numCol,records,index,"account",false);
    else editRecord0(numRow, numCol, records, sizeArray, index);
}

int editRecord1 (int numRow, int numCol, record *records, int index, string category, bool error) {
    printTopRow(numCol);
    int linesOfText = 5;
    cout << "Edit Record" << endl;
    if (error)
        cout << "Error! Please enter a number. ";
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
    if (category == "amount") {
        cin.clear();
        cin >> input;
    }
    else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(cin, input);
    }
    if (input == "x")
        return 0;
    else {
        if (category == "type") {
            records[index-1].type = input;
            return 1;
        }
        if (category == "amount") {
            if (!isNumber(input))
                editRecord1(numRow,numCol,records,index,category,true);
            else {
                cout << input << endl; 
                records[index-1].amount = stod(input);
            }
            return 1;
        }
        if (category == "account") {
            records[index-1].account = input;
            return 1;
        }
    }
}

int editRecord2 (int numRow, int numCol, record *records, int index) {
    printTopRow(numCol);
    int linesOfText = 5;
    cout << "Edit Record" << endl;
    cout << "Record saved! Enter [x] to exit." << endl;
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
    if (input != 'x')
        editRecord2(numRow, numCol, records, index);
}

void editRecord (int numRow, int numCol, record *&records, int &sizeArray, int index) {
    if (editRecord0(numRow, numCol, records, sizeArray, index)) {
        editRecord2(numRow, numCol, records, index);
    }
}