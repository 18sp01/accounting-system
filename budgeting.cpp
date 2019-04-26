#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include "stdInterface.h"
#include "viewRecords.h"
#include "addRecord.h"
using namespace std;

// Function: Allows more intuitive creation of struct tm objects
// Inputs: in integer, the time to be set for the object
// Outputs: a struct tm object with time properly formatted
struct tm setTime(int hour, int min, int sec, int day, int month, int year) {
    struct tm setBudgetTime;
    setBudgetTime.tm_hour = hour;
    setBudgetTime.tm_min = min;
    setBudgetTime.tm_sec = sec;
    setBudgetTime.tm_mon = month - 1; // tm_mon start counting from 0
    setBudgetTime.tm_mday = day;
    setBudgetTime.tm_year = year - 1900; // tm_year starts counting from 1900
    return setBudgetTime;
}

// Function: Outputs string of remaining time in the current period in days, hours, minutes, seconds
// Inputs: in integer, the remaining time in seconds
// Outputs: string of remaining time in the current period in days, hours, minutes, seconds
string remainingTime(int remainingTimeInSeconds) {
    int remainingTimeDays = remainingTimeInSeconds / 86400;
    int remainingTimeHours = (remainingTimeInSeconds - (remainingTimeDays * 86400)) / 3600;
    int remainingTimeMinutes = (remainingTimeInSeconds - (remainingTimeDays * 86400) - (remainingTimeHours * 3600)) / 60;
    int remainingTimeSeconds = remainingTimeInSeconds - (remainingTimeDays * 86400) - (remainingTimeHours * 3600) - (remainingTimeMinutes * 60);
    return to_string(remainingTimeDays) + " days " + to_string(remainingTimeHours) + " hours " + to_string(remainingTimeMinutes) + " minutes " + to_string(remainingTimeSeconds) + " seconds";
}

// Function: From how long has elapsed since the beginning of the budgeting period, compared with how long has elapsed since each expense was added, outputs the total value of expenses in this budgeting period
// Inputs: in integer, the elapsed time since the beginning of the budgeting period in seconds, the array of recoreds, and the size of the array.
// Outputs: a double float of the total value of expenses within this budgeting period (positive)
double totalPeriodExpense(record *records, int sizeArray, int elapsedTimeInSeconds) {
    double totalPeriodExpense = 0;
    time_t now = time(NULL);
    struct tm addtime;
    for (int i = 0; i < sizeArray; i++) {
        record r = records[i];
        addtime = setTime(r.hour,r.min,r.sec,r.day,r.month,r.year);
        if (difftime(now,mktime(&addtime)) < elapsedTimeInSeconds) {
            if (r.amount < 0) // checks whether the record is an income / expense
                totalPeriodExpense -= r.amount; // adds to total as a positive number
        }
    }
    return totalPeriodExpense;
}

// Function: getSetBudgetTime: Gets user's budgeting information from budgeting.txt
// Inputs: reference to struct tm object setBudgetTime (time object which hold when user set the budget), integer in seconds of the duration of their budgeting period, and double budgetAmount
// Outputs: a double float of the total value of expenses within this budgeting period (positive)
int getSetBudgetTime(struct tm &setBudgetTime, int &periodSeconds, double &budgetAmount) {
    ifstream fin;
    fin.open("budgeting.txt");
    if(fin.fail()) {
        cout << "budgeting.txt not found! Please create a new empty budgeting.txt if this message appears." << endl;
        exit(1);
    }
    string line;
    string day, month, year, hour, min, sec, pSeconds, bAmount;
    while (getline(fin, line)) {
        getline(fin, day, ',');
        getline(fin, month, ',');
        getline(fin, year, ',');
        getline(fin, hour, ',');
        getline(fin, min, ',');
        getline(fin, sec, ',');
        getline(fin, pSeconds, ',');
        getline(fin, bAmount, ',');
        setBudgetTime = setTime(stoi(hour), stoi(min), stoi(sec), stoi(day), stoi(month) + 1, stoi(year) + 1900);
        periodSeconds = stoi(pSeconds);
        budgetAmount = stod(bAmount);
        fin.close();
        return 1;
    }
    fin.close();
    return 0;
}

// Function: setBudget: Gets user's budgeting information from interface
// Inputs: reference to struct tm object setBudgetTime (time object which hold when user set the budget), reference to the integer in seconds of the duration of their budgeting period, and reference to the double budgetAmount
// Outputs: If the user finishes editing the information, returns 1, else returns 0
int setBudget(int numRow, int numCol, struct tm &setBudgetTime, int &periodSeconds, double &budgetAmount) {
    string input;
    int pSeconds;
    double bAmount;
    while (true) {
        printTopRow(numCol);
        cout << "Budgeting" << endl;
        cout << "Please enter the number of days you want to budget for." << endl;
        cout << endl;
        cout << "Budget period: " << endl;
        cout << "Budget amount: " << endl;
        for (int i = 0; i < numRow - 9; i++)
            cout << endl;
        cout << "[x] Cancel" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == "x")
            return 0;
        if (isInteger(input)) {
            pSeconds = stoi(input) * 86400; // saves the informtion in a temporary variable
            break;
        }
    }
    while (true) {
        printTopRow(numCol);
        cout << "Budgeting" << endl;
        cout << "Please enter the amount you want to budget for." << endl;
        cout << endl;
        cout << "Budget period: " << input << " days" << endl;
        cout << "Budget amount: " << endl;
        for (int i = 0; i < numRow - 9; i++)
            cout << endl;
        cout << "[x] Exit" << endl;
        printBottomRow(numCol);
        string amount;
        cin >> amount;
        if (amount == "x")
            return 0;
        if (isNumber(amount) && stod(amount) > 0) {
            bAmount = stod(amount);
            break;
        }
    }
    periodSeconds = pSeconds;
    budgetAmount = bAmount;
    time_t now = time(NULL);
    setBudgetTime = *localtime(&now);
    return 1;
}

void writeBudgetToFile(struct tm setBudgetTime, int periodSeconds, double budgetAmount, bool remove) {
    ofstream fout;
    fout.open("budgeting.txt", ofstream::trunc);

    if(fout.fail()) {
        cout << "budgeting.txt not found! Please create a new empty budgeting.txt if this message appears." << endl;
        exit(1);
    }
    if (remove == false) {
        fout << "Day,Month,Year,Hour,Minute,Second,periodSeconds,budgetAmount" << endl;
        fout << setBudgetTime.tm_mday << ',' << setBudgetTime.tm_mon << ',' << setBudgetTime.tm_year << ',' << setBudgetTime.tm_hour << ',' << setBudgetTime.tm_min << ',' << setBudgetTime.tm_sec << ',' << periodSeconds << ',' << budgetAmount << ',';
    }
    fout.close();
}

void budgetingMenu(int numRow, int numCol, record *&records, int &sizeArray) {
    int periodSeconds;
    struct tm setBudgetTime;
    bool budgetingActive = false;
    int diffSeconds;
    double budgetAmount;
    int elapsedTimeInSeconds;
    int remainingTimeInSeconds;
    char input;
    double remainingAmount;
    bool overspent = false;
    while (true) {
        time_t now = time(NULL);
        if (getSetBudgetTime(setBudgetTime, periodSeconds, budgetAmount) != 0) {
            budgetingActive = true;
            diffSeconds = difftime(now,mktime(&setBudgetTime));
            elapsedTimeInSeconds = diffSeconds % periodSeconds;
            remainingTimeInSeconds = periodSeconds - elapsedTimeInSeconds;
            remainingAmount = budgetAmount - totalPeriodExpense(records, sizeArray, elapsedTimeInSeconds);
            if (remainingAmount < 0)
                overspent = true;
            else
                overspent = false;
        }
        printTopRow(numCol);
        cout << "Budgeting" << endl;
        cout << "Please enter [s] to set, or enter [r] to remove the budgeting plan" << (overspent ? " [Warning! You have overspent. Please rebudget]" : "") << endl;
        cout << endl;
        cout << "Budget period: " << (budgetingActive ? to_string(periodSeconds/86400)+" days" : "") << endl;
        cout << "Budget amount: " << (budgetingActive ? to_string(budgetAmount) : "") << endl;
        cout << endl;
        cout << "Time until budget ends: " << (budgetingActive ? remainingTime(remainingTimeInSeconds) : "") << endl;
        cout << "Remaining amount: " << (budgetingActive ? to_string(remainingAmount) : "") << endl;
        for (int i = 0; i < numRow - 12; i++)
            cout << endl;
        cout << "[s] Set New Budget  [r] Remove  [x] Exit" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == 'x')
            break;
        if (input == 's') {
            if (setBudget(numRow, numCol, setBudgetTime, periodSeconds, budgetAmount) != 0)
                writeBudgetToFile(setBudgetTime, periodSeconds, budgetAmount, false);
        }
        if (input == 'r') {
            budgetingActive = false;
            writeBudgetToFile(setBudgetTime, periodSeconds, budgetAmount, true);
        }
    }
} 
