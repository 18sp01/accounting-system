#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>
#include "stdInterface.h"
#include "viewRecords.h"
#include "filterRecords.h"
using namespace std;

void calculatePercent(double graphValue[5], double graphValuePercent[5]) {
    double maxVal = graphValue[0];
    for (int i = 0; i < 5; i++) {
        if (maxVal < abs(graphValue[i])) {
            maxVal = abs(graphValue[i]);
        }
    }
    for (int i = 0; i < 5; i++) {
        if (maxVal != 0)
            graphValuePercent[i] = abs(graphValue[i]/maxVal);
        else
            graphValuePercent[i] = 0;
    }
}

int addGraph(int numRow, int numCol, record *&records, int &sizeArray, int graphNumber, string graphName[5], double graphValue[5], double graphValuePercent[5]) {
    while(true) {
        printTopRow(numCol);
        cout << "Edit Graphs" << endl;
        cout << endl;
        cout << "Please enter a number to add a graph of the corresponding type, or [r] to remove a graph" << endl;
        cout << endl;
        cout << "1. Total Income" << endl;
        cout << "2. Total Expense" << endl;
        cout << "3. Type" << endl;
        cout << "4. Account" << endl;
        cout << "5. Total Income and Expense" << endl;
        for (int i = 0; i < numRow - 13; i++)
            cout << endl;
        cout << "[1/2/3/4/5] Add  [r] Remove  [x] Exit" << endl;
        printBottomRow(numCol);
        char input;
        cin >> input;
        if (input == 'x')
            return 0;
        if (input == '1') {
            double totalIncome = 0;
            for (int i = 0; i < sizeArray; i++) {
                if (records[i].amount > 0)
                    totalIncome += records[i].amount;
            }
            graphName[graphNumber] = "Total Income";
            graphValue[graphNumber] = totalIncome;
            break;
        }
        if (input == '2') {
            double totalExpense = 0;
            for (int i = 0; i < sizeArray; i++) {
                if (records[i].amount < 0)
                    totalExpense += records[i].amount;
            }
            graphName[graphNumber] = "Total Expense";
            graphValue[graphNumber] = totalExpense;
            break;
        }
        if (input == '3') {
            string query;
            while(true) {
                printTopRow(numCol);
                cout << "Edit Graphs" << endl;
                cout << endl;
                cout << "Please enter the type to add a graph for";
                cout << endl << endl;
                cout << "Category: Type";
                cout << endl << endl;
                cout << "Type: ";
                for (int i = 0; i < numRow - 10; i++)
                    cout << endl;
                cout << "[x] Exit" << endl;
                printBottomRow(numCol);
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                string input;
                getline(cin,input);
                if (input == "x")
                    return 0;
                else
                    query = input;
                    break;
            }
            double typeExpense = 0;
            for (int i = 0; i < sizeArray; i++) {
                if (stringCompare(records[i].type, query))
                    typeExpense += records[i].amount;
            }
            graphName[graphNumber] = query + " (Type)";
            graphValue[graphNumber] = typeExpense;
            break;
        }
        if (input == '4') {
            string query;
            while(true) {
                printTopRow(numCol);
                cout << "Edit Graphs" << endl;
                cout << endl;
                cout << "Please enter the account to add a graph for";
                cout << endl << endl;
                cout << "Category: Account";
                cout << endl << endl;
                cout << "Account: ";
                for (int i = 0; i < numRow - 10; i++)
                    cout << endl;
                cout << "[x] Exit" << endl;
                printBottomRow(numCol);
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                string input;
                getline(cin,input);
                if (input == "x")
                    return 0;
                else
                    query = input;
                    break;
            }
            double accountExpense = 0;
            for (int i = 0; i < sizeArray; i++) {
                if (stringCompare(records[i].account, query))
                    accountExpense += records[i].amount;
            }
            graphName[graphNumber] = query + " (Account)";
            graphValue[graphNumber] = accountExpense;
            break;
        }
        if (input == '5') {
            double total = 0;
            for (int i = 0; i < sizeArray; i++) {
                total += records[i].amount;
            }
            graphName[graphNumber] = "Total Income and Expense";
            graphValue[graphNumber] = total;
            break;
        }
        if (input == 'r') {
            graphName[graphNumber] = "";
            graphValue[graphNumber] = 0;
            break;
        }
    }
}

int showGraph(int numRow, int numCol, record *&records, int &sizeArray, string graphName[5], double graphValue[5], double graphValuePercent[5]) {
    int maxlen = (numCol-1)/2;
    while(true) {
        calculatePercent(graphValue, graphValuePercent);
        printTopRow(numCol);
        cout << "Statistical Graphs" << endl;
        cout << endl << endl;
        for (int i = 0; i < 5; i++) {
            if (graphValue[i] >= 0)
                cout << setw(maxlen) << graphName[i] << "|" << string(int(graphValuePercent[i] * maxlen), '*');
            else
                cout  << setw(maxlen) << string(int(graphValuePercent[i] * maxlen), '*') << "|" << graphName[i];
            cout << endl;
        }
        for (int i = 0; i < numRow - 12; i++)
            cout << endl;
        cout << "[x] Exit" << endl;
        printBottomRow(numCol);
        char input;
        cin >> input;
        if (input == 'x')
            return 0;
    }
}


int statGraph(int numRow, int numCol, record *&records, int &sizeArray) {
    string graphName[5] = {"", "", "", "", ""}; 
    double graphValue[5] = {0, 0, 0, 0, 0};
    double graphValuePercent[5];
    while(true) {
        printTopRow(numCol);
        cout << "Statistical Graphs" << endl;
        cout << endl;
        cout << "Please enter a number to add a graph at the corresponding slot, and enter [s] to show the graphs" << endl;
        cout << endl;
        cout << "1. " << graphName[0] << endl;
        cout << "2. " << graphName[1] << endl;
        cout << "3. " << graphName[2] << endl;
        cout << "4. " << graphName[3] << endl;
        cout << "5. " << graphName[4] << endl;
        for (int i = 0; i < numRow - 13; i++)
            cout << endl;
        cout << "[1/2/3/4/5] Add  [s] Show  [x] Exit" << endl;
        printBottomRow(numCol);
        char input;
        cin >> input;
        if (input == 'x')
            return 0;
        if (input == '1')
            addGraph(numRow, numCol, records, sizeArray, 0, graphName, graphValue, graphValuePercent);
        if (input == '2')
            addGraph(numRow, numCol, records, sizeArray, 1, graphName, graphValue, graphValuePercent);
        if (input == '3')
            addGraph(numRow, numCol, records, sizeArray, 2, graphName, graphValue, graphValuePercent);
        if (input == '4')
            addGraph(numRow, numCol, records, sizeArray, 3, graphName, graphValue, graphValuePercent);
        if (input == '5')
            addGraph(numRow, numCol, records, sizeArray, 4, graphName, graphValue, graphValuePercent);
        if (input == 's')
            showGraph(numRow, numCol, records, sizeArray, graphName, graphValue, graphValuePercent);
        if (input != 's')
            showGraph(numRow, numCol, records, sizeArray, graphName, graphValue, graphValuePercent);
    }
}