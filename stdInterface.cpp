#include <iostream>
#include <string>
#include <fstream>
#include "stdInterface.h"
#include "editRecords.h"
#include "addRecord.h"
#include "viewRecords.h"
#include "fromtoFile.h"
#include "sortRecords.h"
#include "statReport.h"
#include "budgeting.h"
using namespace std;


// Function: Updates the size of the records array with sizeChange
// Inputs: Reference to the dynamic array records, the current size of the records, and the desired sizeChange
// Outputs: Changes size of records
void updateRecordsSize(record *&records, int &sizeArray, int sizeChange) {
    record *newRecords = new record[sizeArray+sizeChange];
    for (int i = 0; i < sizeArray; i++) {
        newRecords[i] = records[i];
    }
    sizeArray += sizeChange;
    delete [] records;
    records = newRecords;
}

// Function: Simple functions that prints the top row with '#' characters
void printTopRow(int numCol) {
    cout << string(numCol,'#') << endl;
}

// Function: Simple functions that prints the bottom row with '#' characters
void printBottomRow(int numCol) {
    cout << string(numCol,'#') << endl;
}

// Function: writeConfigToFile: writes the data numRow and numCol to the file configurations.txt
// Inputs: integers numRow and numCol
// Outputs: updates configurations.txt
void writeConfigToFile(int numRow, int numCol) {
    ofstream fout;
    fout.open("configurations.txt", ofstream::trunc);
    if(fout.fail()) {
        cout << "configurations.txt not found! Please create a new empty configurations.txt if this message appears." << endl;
        exit(1);
    }
    fout << "numRow,numCol" << endl;
    fout << numRow << ',' << numCol;
    fout.close();
}

// Function: configurationsMenu: The configurations interface, allows users to change the dimensions of the program
// Inputs: integers numRow and numCol
// Outputs: updates configurations.txt
void configurationsMenu(int &numRow, int &numCol) {
    while (true) {
        printTopRow(numCol);
        cout << "Configurations" << endl;
        cout << " Please enter the number of corresponding to the item you want to change, or enter [r] to reset" << endl;
        cout << endl;
        cout << "1. Number of rows to display (>= 14): " << numRow << endl;
        cout << "2. Number of columns to display (>= 99):  " << numCol << endl;
        for (int i = 0; i < numRow - 9; i++)
            cout << endl;
        cout << "[1/2] Edit item  [r] Reset  [x] Exit" << endl;
        printBottomRow(numCol);
        char input;
        cin >> input;
        if (input == 'x')
            break;
        if (input == '1') {
            while (true) {
                string rows;
                printTopRow(numCol);
                cout << "Configurations" << endl;
                cout << " Please enter the number of rows you want to display (integer larger or equal to 14)." << endl;
                cout << endl;
                cout << "1. Number of rows to display (>= 14): " << numRow << endl;
                cout << "2. Number of columns to display (>= 99):  " << numCol << endl;
                for (int i = 0; i < numRow - 9; i++)
                    cout << endl;
                cout << "[x] Cancel" << endl;
                printBottomRow(numCol);
                cin >> rows;
                if (rows == "x")
                    break;
                if (isInteger(rows) && stoi(rows) >= 14) {
                    numRow = stoi(rows);
                    writeConfigToFile(numRow, numCol);
                    break;
                }
            }
        }
        if (input == '2') {
            while (true) {
                string columns;
                printTopRow(numCol);
                cout << "Configurations" << endl;
                cout << " Please enter the number of columns you want to display (integer larger or equal to 14)." << endl;
                cout << endl;
                cout << "1. Number of rows to display (>= 14): " << numRow << endl;
                cout << "2. Number of columns to display (>= 99):  " << numCol << endl;
                for (int i = 0; i < numRow - 9; i++)
                    cout << endl;
                cout << "[x] Cancel" << endl;
                printBottomRow(numCol);
                cin >> columns;
                if (columns == "x")
                    break;
                if (isInteger(columns) && stoi(columns) >= 99) {
                    numCol = stoi(columns);
                    writeConfigToFile(numRow, numCol);
                    break;
                }
            }
        }
        if (input == 'r') {
            numCol = 99;
            numRow = 14;
            writeConfigToFile(numRow, numCol);
        }
    }
}

// Function: getConfigFromFile: get config info from configurations.txt
// Inputs: reference to the integers numRow and numCol
// Outputs: updated numRow and numCol
int getConfigFromFile(int &numRow, int &numCol) {
    ifstream fin;
    fin.open("configurations.txt");
    if(fin.fail()) {
        cout << "configurations.txt not found! Please create a new empty configurations.txt if this message appears." << endl;
        exit(1);
    }
    string line;
    string nRow, nCol;
    while (getline(fin, line)) {
        getline(fin, nRow, ',');
        getline(fin, nCol, ',');
        numRow = stoi(nRow);
        numCol = stod(nCol);
        fin.close();
        return 1;
    }
    fin.close();
    return 0;
}

// Function: printMainMenu: Prints the main menu
// Inputs: number of rows and number of columns
// Outputs: none
void printMainMenu(int numRow, int numCol) {
    printTopRow(numCol);
    int linesOfText = 8;
    cout << "Easy Accounting System" << endl;
    cout << "by Tam Fong Ching Herbert and Park Sangwon" << endl;
    cout << "" << endl;
    cout << "Please enter a command:" << endl;
    cout << "[a] Add Record" << endl;
    cout << "[v] View Records" << endl;
    cout << "[s] Statistics" << endl;
    cout << "[b] Budgeting" << endl;
    cout << "[c] Configurations" << endl;
    for (int i = 0; i < numRow - 5 - linesOfText; i++)
        cout << endl;
    cout << "[x] Exit" << endl;
    printBottomRow(numCol);
}

// Function: main: prints the first interface when users enter the program
// Inputs: user input
// Outputs: exit or calls other interfaces
int main(int argc, char ** argv) {
    int numCol, numRow;
    if (getConfigFromFile(numRow,numCol) == 0) {
        numCol = 99;
        numRow = 14;
    }
    int sizeArray = 0;
    record *records = new record[sizeArray];
    readFromFile(sizeArray, records);
    printMainMenu(numRow, numCol);
    char command;
    cin >> command;
    while (command != 'x') {
        switch (command) {
            case 'a': {
                record newRecord;
                printAddRecord(numRow, numCol, sizeArray, records, newRecord);
                break;
            }
            case 'v': {
                viewRecordPages(numRow, numCol, sizeArray, records);
                break;
            }
            case 's': {
                statReports(numRow, numCol, records, sizeArray);
                break;
            }
            case 'b': {
                budgetingMenu(numRow, numCol, records, sizeArray);
                break;
            }
            case 'c': {
                configurationsMenu(numRow, numCol);
                break;
            }
        }
        printMainMenu(numRow, numCol);
        cin >> command;
    }
    writeToFile(sizeArray, records);
    delete[] records;
}