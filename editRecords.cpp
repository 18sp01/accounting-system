#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <iomanip>
#include "stdInterface.h"
#include "addRecord.h"
#include "viewRecords.h"
#include "editRecords.h"
using namespace std;

// Function: removeRecord: remove a record from records
// Inputs: reference to dynamic array records, reference to size of records, the index of the record to be removed
// Outputs: changes to records, changes to sizeArray
void deleteRecord(record *&records, int &sizeArray, int index) {
    record *newRecords = new record[sizeArray-1];
    bool shifted = false;
    int j = 0;
    for (int i = 0; i < sizeArray-1; i++) {
        cout << i << endl;
        newRecords[i] = records[j];
        if (i == index && !shifted) {
            shifted = true;
            i--;
        }
        j++;
    }
    sizeArray -= 1;
    delete [] records;
    records = newRecords;
}

// header to allow editRecord0 to call editRecord1
int editRecord1 (int numRow, int numCol, record *records, int index, string category, bool error);

// Function: editRecord0: first edit record interface
// Inputs: reference to dynamic array records, reference to size of records, the index of the record, user input
// Outputs: changes to records, changes to sizeArray, editRecord1
int editRecord0 (int numRow, int numCol, record *&records, int &sizeArray, int index) {
    printTopRow(numCol);
    cout << "Edit Record" << endl;
    cout << "Please enter [1], [2] or [3] to edit the corresponding data, or enter [d] to delete the record" << endl;
    cout << endl;
    printCategories(); // categories
    cout << endl;
    printRecord(records,index-1);
    for (int i = 0; i < numRow - 9; i++)
        cout << endl;
    cout << "[1] Amount  [2] Type  [3] Account  [d] Delete  [x] Cancel" << endl;
    printBottomRow(numCol);
    char input;
    cin >> input;
    if (input == 'x')
        return 0;
    if (input == 'd') {
        deleteRecord(records, sizeArray, index-1);
        return 0;
    }
    if (input == '1')
        return editRecord1(numRow,numCol,records,index,"amount",false);
    if (input == '2')
        return editRecord1(numRow,numCol,records,index,"type",false);
    if (input == '3')
        return editRecord1(numRow,numCol,records,index,"account",false);
    else editRecord0(numRow, numCol, records, sizeArray, index); // calls editRecord0 recursively
}

// Function: editRecord1: second edit record interface, gets input for the value to edit with
// Inputs: dynamic array records, the index of the record, string category, bool error, user input
// Outputs: changes to records, changes to sizeArray
int editRecord1 (int numRow, int numCol, record *records, int index, string category, bool error) {
    printTopRow(numCol);
    cout << "Edit Record" << endl;
    if (error)
        cout << "Error! Please enter a number. ";
    cout << "Please enter the " << category << endl;
    cout << "" << endl;
    printCategories();
    cout << endl;
    printRecord(records,index-1);
    for (int i = 0; i < numRow - 9; i++)
        cout << endl;
    cout << "[x] Cancel" << endl;
    printBottomRow(numCol);
    string input;
    if (category == "amount") {
        cin.clear();
        cin >> input;
    }
    else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // handles multi word inputs
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

// Function: editRecord2: third edit record interface
// Inputs: dynamic array records, the index of the record
// Outputs: changes to records, changes to sizeArray, editRecord1
int editRecord2 (int numRow, int numCol, record *records, int index) {
    printTopRow(numCol);
    cout << "Edit Record" << endl;
    cout << "Record saved! Enter [x] to exit." << endl;
    cout << "" << endl;
    printCategories();
    cout << endl;
    printRecord(records,index-1);
    for (int i = 0; i < numRow - 9; i++)
        cout << endl;
    cout << "[x] Exit" << endl;
    printBottomRow(numCol);
    char input;
    cin >> input;
    if (input != 'x')
        editRecord2(numRow, numCol, records, index);
}

// function to call editRecord0 and editRecord2 properly
void editRecord (int numRow, int numCol, record *&records, int &sizeArray, int index) {
    if (editRecord0(numRow, numCol, records, sizeArray, index))
        editRecord2(numRow, numCol, records, index);
}


/*
the editfRecord functions is are versions of the original editRecord functions but tuned to edit filter records instead. Therefore
besides editing the filtered fRecords, it also edits the original records array.
*/
int editfRecord1 (int numRow, int numCol, record *fRecords, int index, record *records, string category, bool error);

// Function: editfRecord0: first edit record interface in filterRecords
// Inputs: reference to dynamic array records and fRecords, reference to size of records and fRecords, the index of the record, user input
// Outputs: changes to records and fRecords, changes to sizeArray and fsizeArray, editfRecord1
int editfRecord0 (int numRow, int numCol, record *&fRecords, int &fsizeArray, int index, record *&records, int &sizeArray) {
    printTopRow(numCol);
    int linesOfText = 6;
    cout << "Edit Record" << endl;
    cout << "Please enter [1], [2] or [3] to edit the corresponding data, or enter [d] to delete the record" << endl;
    cout << endl;
    printCategories();
    cout << endl;
    printRecord(fRecords,index-1);
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << endl;
    cout << "[1] Amount  [2] Type  [3] Account  [d] Delete  [x] Cancel" << endl;
    printBottomRow(numCol);
    char input;
    cin >> input;
    if (input == 'x')
        return 0;
    if (input == 'd') {
        deleteRecord(records, sizeArray, fRecords[index-1].originalIndex);
        deleteRecord(fRecords, fsizeArray, index-1);
        return 0;
    }
    if (input == '1')
        return editfRecord1(numRow, numCol, fRecords, index, records,"amount",false);
    if (input == '2')
        return editfRecord1(numRow, numCol, fRecords, index, records,"type",false);
    if (input == '3')
        return editfRecord1(numRow, numCol, fRecords, index, records,"account",false);
    else editfRecord0(numRow, numCol, fRecords, fsizeArray, index, records, sizeArray);
}

// Function: editfRecord1: second edit record interface in filterRecords, gets input for the value to edit with
// Inputs: dynamic array records and fRecords, the index of the record, user input, string category, bool error
// Outputs: changes to records and fRecords, changes to sizeArray and fsizeArray, editfRecord1
int editfRecord1 (int numRow, int numCol, record *fRecords, int index, record *records, string category, bool error) {
    printTopRow(numCol);
    cout << "Edit Record" << endl;
    if (error)
        cout << "Error! Please enter a number. ";
    cout << "Please enter the " << category << endl;
    cout << "" << endl;
    printCategories();
    cout << endl;
    printRecord(fRecords,index-1);
    for (int i = 0; i < numRow - 9; i++)
        cout << endl;
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
            fRecords[index-1].type = input;
            records[fRecords[index-1].originalIndex].type = input;
            return 1;
        }
        if (category == "amount") {
            if (!isNumber(input))
                editfRecord1(numRow, numCol, fRecords, index, records, category, true);
            else {
                fRecords[index-1].amount = stod(input);
                records[fRecords[index-1].originalIndex].amount = stod(input);
            }
            return 1;
        }
        if (category == "account") {
            fRecords[index-1].account = input;
            records[fRecords[index-1].originalIndex].account = input;
            return 1;
        }
    }
}

// Function: editRecord2: third edit record interface in filterRecords
// Inputs: reference to dynamic array records and fRecords, the index of the record
// Outputs: changes to records and fRecords
int editfRecord2 (int numRow, int numCol, record *fRecords, int index, record *records) {
    printTopRow(numCol);
    cout << "Edit Record" << endl;
    cout << "Record saved! Enter [x] to exit." << endl;
    cout << "" << endl;
    printCategories();
    cout << endl;
    printRecord(fRecords,index-1);
    for (int i = 0; i < numRow - 9; i++)
        cout << endl;
    cout << "[x] Exit" << endl;
    printBottomRow(numCol);
    char input;
    cin >> input;
    if (input != 'x')
        editfRecord2(numRow, numCol, fRecords, index, records);
}

void editfRecord (int numRow, int numCol, record *&fRecords, int &fsizeArray, int index, record *&records, int &sizeArray) {
    if (editfRecord0(numRow, numCol, fRecords, fsizeArray, index, records, sizeArray)) {
        editfRecord2(numRow, numCol, fRecords, index, records);
    }
}