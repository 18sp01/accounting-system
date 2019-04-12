#include <iostream>
#include <string>
#include <vector>
#include "editRecords.h"
#include "stdInterface.h"
#include "addRecord.h"
#include "viewRecords.h"
using namespace std;

// Function: 
// Inputs: 
// Outputs: 
void printTopRow(int numCol) {
    cout << string(numCol+2,'#') << endl;
}

// Function: 
// Inputs: 
// Outputs: 
void printBottomRow(int numCol) {
    cout << string(numCol+2,'#') << endl;
}

// Function: 
// Inputs: 
// Outputs: 
string convertStringtoLine(string s, int numCol);

// Function: 
// Inputs: 
// Outputs: 
void printMainMenu(int numRow, int numCol) {
    printTopRow(numCol);
    int linesOfText = 8;
    cout << convertStringtoLine("Easy Accounting System",numCol) << endl;
    cout << convertStringtoLine("by Tam Fong Ching Herbert and Park Sangwon",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("Please enter a command:",numCol) << endl;
    cout << convertStringtoLine("[a] Add Record",numCol) << endl;
    cout << convertStringtoLine("[v] View Records",numCol) << endl;
    cout << convertStringtoLine("[e] Edit Records",numCol) << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << string(numCol,' ') << endl;
    cout << convertStringtoLine("[x] Exit",numCol) << endl;
    printBottomRow(numCol);
}

// Function: 
// Inputs: 
// Outputs: 
string convertStringtoLine(string s, int numCol) {
    s = " " + s + string(numCol-s.length(),' ') + " ";
    return s;
}

int main(int argc, char ** argv) {
    // w.ws_row give number of rows, w.ws_col gives number of columns
    // struct winsize w;
    // ioctl(fileno(stdout), TIOCGWINSZ, &w);
    // w.ws_col = w.ws_col / 2;

    int numCol = 80;
    int numRow = 12;

    vector<record> records;

    printMainMenu(numRow, numCol);
    char command;
    cin >> command;
    while (command != 'x') {
        switch (command) {
            case 'a': {
                record newRecord;
                printAddRecord(numRow, numCol, records, newRecord);
                break;
            }
            case 'v': {
                printPages(numRow, numCol, records);
                break;
            }
            case 'e': {
                break;
            }
        }
        printMainMenu(numRow, numCol);
        cin >> command;
    }
}