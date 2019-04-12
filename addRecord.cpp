#include <iostream>
#include <string>
#include <vector>
#include "records.h"
#include "stdInterface.h"
#include "addRecord.h"
using namespace std;

int printAddRecord0(int numRow, int numCol, record &record) {
    printTopRow(numCol);
    int linesOfText = 8;
    cout << convertStringtoLine("Add Record",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("Please enter type of income/expense (e.g. food, game, salary, etc.)",numCol) << endl;
    cout << convertStringtoLine("Type of income/expense: ",numCol) << endl;
    cout << convertStringtoLine("Amount: ",numCol) << endl;
    cout << convertStringtoLine("Account: ",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("[x] Cancel",numCol) << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    printBottomRow(numCol);
    string input;
    cin >> input;
    if (input == "x") {
        return 0;
    }
    else {
        record.type = input;
        return 1;
    }
}

int printAddRecord1(int numRow, int numCol, record &record) {
    printTopRow(numCol);
    int linesOfText = 8;
    cout << convertStringtoLine("Add Record",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("Please enter the amount",numCol) << endl;
    cout << convertStringtoLine("Type of income/expense: " + record.type,numCol) << endl;
    cout << convertStringtoLine("Amount: ",numCol) << endl;
    cout << convertStringtoLine("Account: ",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("[x] Cancel",numCol) << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    printBottomRow(numCol);
    string input;
    cin >> input;
    if (input == "x") {
        return 0;
    }
    else {
        record.amount = stof(input);
        return 1;
    }
}

int printAddRecord2(int numRow, int numCol, record &record) {
    printTopRow(numCol);
    int linesOfText = 8;
    cout << convertStringtoLine("Add Record",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("Please enter the account used (e.g. cash, bank card, credit card, etc.)",numCol) << endl;
    cout << convertStringtoLine("Type of income/expense: " + record.type,numCol) << endl;
    cout << convertStringtoLine("Amount: " + to_string(record.amount),numCol) << endl;
    cout << convertStringtoLine("Account: ",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("[x] Cancel",numCol) << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    printBottomRow(numCol);
    string input;
    cin >> input;
    if (input == "x") {
        return 0;
    }
    else {
        record.account = input;
        return 1;
    }
}

int printAddRecord3(int numRow, int numCol, record &record) {
    printTopRow(numCol);
    int linesOfText = 8;
    cout << convertStringtoLine("Add Record",numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("Record Saved! Enter [x] to exit.",numCol) << endl;
    cout << convertStringtoLine("Type of income/expense: " + record.type,numCol) << endl;
    cout << convertStringtoLine("Amount: " + to_string(record.amount),numCol) << endl;
    cout << convertStringtoLine("Account: " + record.account,numCol) << endl;
    cout << convertStringtoLine("",numCol) << endl;
    cout << convertStringtoLine("[x] Exit",numCol) << endl;
    for (int i = 0; i < numRow - 3 - linesOfText; i++)
        cout << " " << string(numCol,' ') << " " << endl;
    printBottomRow(numCol);
    char input;
    cin >> input;
    while (input != 'x') {
        cin >> input;
    }
}

void printAddRecord(int numRow, int numCol, vector<record> &records, record &newRecord) {
    if (printAddRecord0(numRow, numCol,newRecord) != 0) {
        if (printAddRecord1(numRow, numCol,newRecord) != 0) {
            if (printAddRecord2(numRow, numCol,newRecord) != 0) {
                printAddRecord3(numRow, numCol,newRecord);
                records.push_back(newRecord);
            }
        }
    }
}