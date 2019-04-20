#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "stdInterface.h"
#include "viewRecords.h"
using namespace std;

void listReports(int numRow, int numCol, string *&reports, int sizeReports) {
    cout << setw(5) << left << '#' << " | ";
    cout << setw(15) << left << "Type";
    cout << endl;
    for (int i = 0; i < sizeReports; i++) {
        cout << setw(5) << left << i+1 << " | ";
        cout << setw(15) << reports[i];
        cout << endl;
    }
}

void incomeReports() {
    cout << "income reports" << endl;
}

void expenseReports() {
    cout << "expense reports" << endl;
}

void statReports(int numRow, int numCol, record *&records, int &sizeArray) {
    char input = '0';
    int sizeReports = 3;
    string * reports = new string[sizeReports] {"Income", "Expense", "Others"};
    while (true) {
        printTopRow(numCol);
        cout << "Statistical Reports" << endl;
        cout << "Please enter a number to view the corresponding report, or enter [x] to exit" << endl;
        cout << endl;
        listReports(numRow, numCol, reports, sizeReports);
        for (int i = 0; i < numRow - 11; i++)
            cout << endl;
        cout << "[x] Exit" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == 'x')
            break;
        if (input == '1') {
            incomeReports();
            break;
        }
        // filter by account
        if (input == '2') {
            expenseReports();
            break;
        }
        // filter by date
        if (input == '3') {
            //other;
            break;
        }
    }
}