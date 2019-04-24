#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "stdInterface.h"
#include "viewRecords.h"
#include "filterRecords.h"
using namespace std;

void addGraph(int numRow, int numCol, record *&records, int &sizeArray, int graphNumber, string &graphName[5], double &graphValue[5], double &graphValuePercent[5]) {
    while(true) {
        printTopRow(numCol);
        cout << "Statistical Graphs" << endl;
        cout << endl;
        cout << "Please enter a number to add a graph of the corresponding type, or [r] to remove a graph" << endl;
        cout << endl;
        cout << "1. Total Income";
        cout << "2. Total Expense";
        cout << "3. Type";
        cout << "4. Account";
        cout << "5. Total Income and Expense";
        for (int i = 0; i < numRow - 8; i++)
            cout << endl;
        cout << "[1/2/3/4/5] Add  [r] Remove  [x] Exit" << endl;
        printBottomRow(numCol);
        char input;
        cin >> input;
        if (input == 'x')
            return 0;
        if (input =)
        if (input == 'a')
            addGraph(numRow, numCol, records, sizeArray, graphName, graphValue, graphValuePercent);
    }
}

void showGraph(int numRow, int numCol, record *&records, int &sizeArray, string &graphName[5], double &graphValue[5], double &graphValuePercent[5]) {
    int maxlen = (numCol-1)/2
    for (int i = 0; i < 5; i++) {
        cout << setw(maxlen) << "|" << endl;
    }
}


void statGraph(int numRow, int numCol, record *&records, int &sizeArray) {
    string graphName[5] = {"Empty", "Empty", "Empty", "Empty", "Empty"}; 
    double graphValue[5] = {0, 0, 0, 0, 0};
    double graphValuePercent[5];
    while(true) {
        printTopRow(numCol);
        cout << "Statistical Graphs" << endl;
        cout << endl;
        cout << "Please enter a number to add a graph at the corresponding slot, and enter [s] to show the graphs" << endl;
        cout << endl;
        cout << "1. " << graphName[0];
        cout << "2. " << graphName[1];
        cout << "3. " << graphName[2];
        cout << "4. " << graphName[3];
        cout << "5. " << graphName[4];
        for (int i = 0; i < numRow - 8; i++)
            cout << endl;
        cout << "[1/2/3/4/5] Add  [s] Show  [x] Exit" << endl;
        printBottomRow(numCol);
        char input;
        cin >> input;
        if (input == 'x')
            return 0;
        if (input == '1' or )
            addGraph(numRow, numCol, records, sizeArray, graphNumber, graphName, graphValue, graphValuePercent);
    }
}