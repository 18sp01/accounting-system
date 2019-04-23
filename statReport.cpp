#include <iostream>
#include <ios>
#include <string>
#include <limits>
#include <iomanip>
#include "stdInterface.h"
#include "viewRecords.h"
#include "filterRecords.h"
using namespace std;

void listReports(int numRow, int numCol, string *&reports, int sizeReports) {
    /*cout << setw(5) << left << '#' << " | ";
    cout << setw(15) << left << "Type";
    cout << endl;
    for (int i = 0; i < sizeReports; i++) {
        cout << setw(5) << left << i+1 << " | ";
        cout << setw(15) << reports[i];
        cout << endl;
    }*/
    for (int i = 0; i < sizeReports; i++) {
        cout << "[" << i+1 << "] ";
        cout << reports[i];
        cout << endl;
    }
}

int searchIncomeDetails(int numRow, int numCol, record *&records, int &sizeArray, double total_income);

int incomeReports(int numRow, int numCol, record *&records, int &sizeArray) {
    while(true) {
        printTopRow(numCol);
        cout << "Income Report" << endl;
        cout << endl;
        cout << "Please enter [s] to find out more details about your income" << endl;
        cout << endl;
        double total_income = 0;
        for (int i = 0; i < sizeArray; i++) {
            if (records[i].amount > 0)
                total_income += records[i].amount;
        }
        cout << "Total Income: " << total_income;
        for (int i = 0; i < numRow - 8; i++)
            cout << endl;
        cout << "[s] Search Details [x] Exit" << endl;
        printBottomRow(numCol);
        char input;
        cin >> input;
        if (input == 'x')
            return 0;
        if (input == 's')
            searchIncomeDetails(numRow, numCol, records, sizeArray, total_income);
    }
}

int searchIncomeDetails(int numRow, int numCol, record *&records, int &sizeArray, double total_income) {
    string category;
    while(true) {
        printTopRow(numCol);
        cout << "Search Income Details" << endl;
        cout << endl;
        cout << "Please enter the category to search details for";
        cout << endl << endl;
        cout << "Category: ";
        for (int i = 0; i < numRow - 8; i++)
            cout << endl;
        cout << "[1] Type [2] Account [3] Date [x] Exit" << endl;
        printBottomRow(numCol);
        char input;
        cin >> input;
        if (input == 'x')
            return 0;
        if (input == '1') {
            category = "Type";
            break;
        }
        if (input == '2') {
            category = "Account";
            break;
        }
        if (input == '3') {
            category = "Date";
            break;
        }
    }
    if (category == "Type") {
        string query;
        while(true) {
            printTopRow(numCol);
            cout << "Search Income Details" << endl;
            cout << endl;
            cout << "Please enter the type to search details for";
            cout << endl << endl;
            cout << "Category: Type";
            cout << endl << endl;
            cout << "Search: ";
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
        while(true) {
            printTopRow(numCol);
            cout << "Search Income Details" << endl;
            cout << endl;
            cout << "Displaying details of " << query;
            cout << endl << endl;
            double query_income = 0;
            for (int i = 0; i < sizeArray; i++) {
                if (stringCompare(records[i].account, query) && records[i].amount > 0)
                    query_income += records[i].amount;
            }
            cout << "Your total " << query << " is " << query_income << endl;
            cout << endl;
            cout << "Your " << query << " is " << (query_income/total_income)*100 << "% of the total income" << endl;
            cout << endl << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            char input;
            cin >> input;
            if (input == 'x')
                return 0;
        }
    }
    if (category == "Account") {
        string query;
        while(true) {
            printTopRow(numCol);
            cout << "Search Income Details" << endl;
            cout << endl;
            cout << "Please enter the account to search details for";
            cout << endl << endl;
            cout << "Category: Account";
            cout << endl << endl;
            cout << "Search: ";
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
        while(true) {
            printTopRow(numCol);
            cout << "Search Income Details" << endl;
            cout << endl;
            cout << "Displaying details of " << query;
            cout << endl << endl;
            double query_income = 0;
            for (int i = 0; i < sizeArray; i++) {
                if (stringCompare(records[i].account, query) && records[i].amount > 0)
                    query_income += records[i].amount;
            }
            cout << "Your income through " << query << " is " << query_income << endl;
            cout << endl;
            cout << "Your income through " << query << " is " << (query_income/total_income)*100 << "% of the total income" << endl;
            cout << endl << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            char input;
            cin >> input;
            if (input == 'x')
                return 0;
        }
    }
    if (category == "Date") {
        record dateRecord;
        while(true) {
            printTopRow(numCol);
            cout << "Search Income Details" << endl;
            cout << endl;
            cout << "Please enter which year to search details for (enter * to skip)";
            cout << endl << endl;
            cout << "Category: Date";
            cout << endl << endl;
            cout << "Year: " << endl;
            cout << "Month: " << endl;
            cout << "Day: " << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            string input;
            cin >> input;
            if (input == "x")
                return 0;
            else {
                if (!isInteger(input) && input != "*")
                    continue;
                else {
                    if (input == "*")
                        input = "-1";
                    dateRecord.year = stoi(input);
                    break;
                }
            }
        }
        while(true) {
            printTopRow(numCol);
            cout << "Search Income Details" << endl;
            cout << endl;
            cout << "Please enter which month to search details for (enter * to skip)";
            cout << endl << endl;
            cout << "Category: Date";
            cout << endl << endl;
            cout << "Year: " << (dateRecord.year == -1 ? "*" : to_string(dateRecord.year)) << endl;
            cout << "Month: " << endl;
            cout << "Day: " << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            string input;
            cin >> input;
            if (input == "x")
                return 0;
            else {
                if (!isInteger(input) && input != "*")
                    continue;
                else {
                    if (input == "*")
                        input = "-1";
                    dateRecord.month = stoi(input);
                    break;
                }
            }
        }
        while(true) {
            printTopRow(numCol);
            cout << "Search Income Details" << endl;
            cout << endl;
            cout << "Please enter the day to search details for (enter * to skip)";
            cout << endl << endl;
            cout << "Category: Date";
            cout << endl << endl;
            cout << "Year: " << (dateRecord.year == -1 ? "*" : to_string(dateRecord.year)) << endl;
            cout << "Month: " << (dateRecord.month == -1 ? "*" : to_string(dateRecord.month)) << endl;
            cout << "Day: " << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            string input;
            cin >> input;
            if (input == "x")
                return 0;
            else {
                if (!isInteger(input) && input != "*")
                    continue;
                else {
                    if (input == "*")
                        input = "-1";
                    dateRecord.day = stoi(input);
                    break;
                }
            }
        }
        while(true) {
            string query = (dateRecord.day == -1 ? "*" : to_string(dateRecord.day)) + "/" + (dateRecord.month == -1 ? "*" : to_string(dateRecord.month)) + "/" + (dateRecord.year == -1 ? "*" : to_string(dateRecord.year));
            printTopRow(numCol);
            cout << "Search Income Details" << endl;
            cout << endl;
            cout << "Displaying details of income on " << query;
            cout << endl << endl;
            double query_income = 0;
            for (int i = 0; i < sizeArray; i++) {
                if (checkDateMatch (dateRecord, records[i]) && records[i].amount > 0)
                    query_income += records[i].amount;
            }
            cout << "Your total income on " << query << " was " << query_income << endl;
            cout << endl;
            cout << "Your total income on " << query << " was " << (query_income/total_income)*100 << "% of the total income" << endl;
            cout << endl << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            char input;
            cin >> input;
            if (input == 'x')
                return 0;
        }
    }
}

int searchExpenseDetails(int numRow, int numCol, record *&records, int &sizeArray, double total_expense);

int expenseReports(int numRow, int numCol, record *&records, int &sizeArray) {
    while(true) {
        printTopRow(numCol);
        cout << "Expense Report" << endl;
        cout << endl;
        cout << "Please enter [s] to find out more details about your expense" << endl;
        cout << endl;
        double total_expense = 0;
        for (int i = 0; i < sizeArray; i++) {
            if (records[i].amount < 0)
                total_expense -= records[i].amount;
        }
        cout << "Total Expense: " << total_expense;
        for (int i = 0; i < numRow - 8; i++)
            cout << endl;
        cout << "[s] Search Details [x] Exit" << endl;
        printBottomRow(numCol);
        char input;
        cin >> input;
        if (input == 'x')
            return 0;
        if (input == 's')
            searchExpenseDetails(numRow, numCol, records, sizeArray, total_expense);
    }
}

int searchExpenseDetails(int numRow, int numCol, record *&records, int &sizeArray, double total_expense) {
    string category;
    while(true) {
        printTopRow(numCol);
        cout << "Search Expense Details" << endl;
        cout << endl;
        cout << "Please enter the category to search details for";
        cout << endl << endl;
        cout << "Category: ";
        for (int i = 0; i < numRow - 8; i++)
            cout << endl;
        cout << "[1] Type [2] Account [3] Date [x] Exit" << endl;
        printBottomRow(numCol);
        char input;
        cin >> input;
        if (input == 'x')
            return 0;
        if (input == '1') {
            category = "Type";
            break;
        }
        if (input == '2') {
            category = "Account";
            break;
        }
        if (input == '3') {
            category = "Date";
            break;
        }
    }
    if (category == "Type") {
        string query;
        while(true) {
            printTopRow(numCol);
            cout << "Search Expense Details" << endl;
            cout << endl;
            cout << "Please enter the type to search details for";
            cout << endl << endl;
            cout << "Category: Type";
            cout << endl << endl;
            cout << "Search: ";
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
        while(true) {
            printTopRow(numCol);
            cout << "Search Expense Details" << endl;
            cout << endl;
            cout << "Displaying details of " << query;
            cout << endl << endl;
            double query_expense = 0;
            for (int i = 0; i < sizeArray; i++) {
                if (stringCompare(records[i].type, query) && records[i].amount < 0)
                    query_expense -= records[i].amount;
            }
            cout << "Your total expense on " << query << " was " << query_expense << endl;
            cout << endl;
            cout << "Your total expense on " << query << " was " << (query_expense/total_expense)*100 << "% of the total expense" << endl;
            cout << endl << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            char input;
            cin >> input;
            if (input == 'x')
                return 0;
        }
    }
    if (category == "Account") {
        string query;
        while(true) {
            printTopRow(numCol);
            cout << "Search Expense Details" << endl;
            cout << endl;
            cout << "Please enter the account to search details for";
            cout << endl << endl;
            cout << "Category: Account";
            cout << endl << endl;
            cout << "Search: ";
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
        while(true) {
            printTopRow(numCol);
            cout << "Search Expense Details" << endl;
            cout << endl;
            cout << "Displaying details of " << query;
            cout << endl << endl;
            double query_expense = 0;
            for (int i = 0; i < sizeArray; i++) {
                if (stringCompare(records[i].account, query) && records[i].amount < 0)
                    query_expense -= records[i].amount;
            }
            cout << "Your " << query << " expense is " << query_expense << endl;
            cout << endl;
            cout << "Your " << query << " expense is " << (query_expense/total_expense)*100 << "% of the total expense" << endl;
            cout << endl << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            char input;
            cin >> input;
            if (input == 'x')
                return 0;
        }
    }
    if (category == "Date") {
        record dateRecord;
        while(true) {
            printTopRow(numCol);
            cout << "Search Expense Details" << endl;
            cout << endl;
            cout << "Please enter which year to search details for (enter * to skip)";
            cout << endl << endl;
            cout << "Category: Date";
            cout << endl << endl;
            cout << "Year: " << endl;
            cout << "Month: " << endl;
            cout << "Day: " << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            string input;
            cin >> input;
            if (input == "x")
                return 0;
            else {
                if (!isInteger(input) && input != "*")
                    continue;
                else {
                    if (input == "*")
                        input = "-1";
                    dateRecord.year = stoi(input);
                    break;
                }
            }
        }
        while(true) {
            printTopRow(numCol);
            cout << "Search Expense Details" << endl;
            cout << endl;
            cout << "Please enter which month to search details for (enter * to skip)";
            cout << endl << endl;
            cout << "Category: Date";
            cout << endl << endl;
            cout << "Year: " << (dateRecord.year == -1 ? "*" : to_string(dateRecord.year)) << endl;
            cout << "Month: " << endl;
            cout << "Day: " << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            string input;
            cin >> input;
            if (input == "x")
                return 0;
            else {
                if (!isInteger(input) && input != "*")
                    continue;
                else {
                    if (input == "*")
                        input = "-1";
                    dateRecord.month = stoi(input);
                    break;
                }
            }
        }
        while(true) {
            printTopRow(numCol);
            cout << "Search Expense Details" << endl;
            cout << endl;
            cout << "Please enter the day to search details for (enter * to skip)";
            cout << endl << endl;
            cout << "Category: Date";
            cout << endl << endl;
            cout << "Year: " << (dateRecord.year == -1 ? "*" : to_string(dateRecord.year)) << endl;
            cout << "Month: " << (dateRecord.month == -1 ? "*" : to_string(dateRecord.month)) << endl;
            cout << "Day: " << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            string input;
            cin >> input;
            if (input == "x")
                return 0;
            else {
                if (!isInteger(input) && input != "*")
                    continue;
                else {
                    if (input == "*")
                        input = "-1";
                    dateRecord.day = stoi(input);
                    break;
                }
            }
        }
        while(true) {
            string query = (dateRecord.day == -1 ? "*" : to_string(dateRecord.day)) + "/" + (dateRecord.month == -1 ? "*" : to_string(dateRecord.month)) + "/" + (dateRecord.year == -1 ? "*" : to_string(dateRecord.year));
            printTopRow(numCol);
            cout << "Search Expense Details" << endl;
            cout << endl;
            cout << "Displaying details of expense on " << query;
            cout << endl << endl;
            double query_expense = 0;
            for (int i = 0; i < sizeArray; i++) {
                if (checkDateMatch (dateRecord, records[i]) && records[i].amount < 0)
                    query_expense -= records[i].amount;
            }
            cout << "Your total expense on " << query << " was " << query_expense << endl;
            cout << endl;
            cout << "Your total expense on " << query << " was " << (query_expense/total_expense)*100 << "% of the total expense" << endl;
            cout << endl << endl;
            for (int i = 0; i < numRow - 13; i++)
                cout << endl;
            cout << "[x] Exit" << endl;
            printBottomRow(numCol);
            char input;
            cin >> input;
            if (input == 'x')
                return 0;
        }
    }
}

void statReports(int numRow, int numCol, record *&records, int &sizeArray) {
    char input = '0';
    int sizeReports = 3;
    string * reports = new string[sizeReports] {"Income", "Expense", "Graphs"};
    while (true) {
        printTopRow(numCol);
        cout << "Statistical Reports" << endl;
        cout << "Please enter a number to view the corresponding report, or enter [x] to exit" << endl;
        cout << endl;
        listReports(numRow, numCol, reports, sizeReports);
        for (int i = 0; i < numRow - 7 - sizeReports; i++)
            cout << endl;
        cout << "[x] Exit" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == 'x')
            break;
        if (input == '1') {
            incomeReports(numRow, numCol, records, sizeArray);
        }
        // filter by account
        if (input == '2') {
            expenseReports(numRow, numCol, records, sizeArray);
        }
        // filter by date
        if (input == '3') {
            //other;
        }
    }
}