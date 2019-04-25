#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include "stdInterface.h"
#include "viewRecords.h"
#include "addRecord.h"
using namespace std;

struct tm setTime(int hour, int min, int sec, int day, int month, int year) {
    struct tm setBudgetTime;
    // get time when user set budget
    setBudgetTime.tm_hour = hour;
    setBudgetTime.tm_min = min;
    setBudgetTime.tm_sec = sec;
    setBudgetTime.tm_mon = month - 1;
    setBudgetTime.tm_mday = day;
    setBudgetTime.tm_year = year - 1900;
    return setBudgetTime;
}

// outputs string of remaining time in the current period in days, hours, minutes, seconds
string remainingTime(int remainingTimeInSeconds) {
    int remainingTimeDays = remainingTimeInSeconds / 86400;
    int remainingTimeHours = (remainingTimeInSeconds - (remainingTimeDays * 86400)) / 3600;
    int remainingTimeMinutes = (remainingTimeInSeconds - (remainingTimeDays * 86400) - (remainingTimeHours * 3600)) / 60;
    int remainingTimeSeconds = remainingTimeInSeconds - (remainingTimeDays * 86400) - (remainingTimeHours * 3600) - (remainingTimeMinutes * 60);
    return to_string(remainingTimeDays) + " days " + to_string(remainingTimeHours) + " hours " + to_string(remainingTimeMinutes) + " minutes " + to_string(remainingTimeSeconds) + " seconds";
}

double totalPeriodExpense(record *&records, int sizeArray, int elapsedTimeInSeconds) {
    double totalPeriodExpense = 0;
    time_t now = time(NULL);
    struct tm addtime;
    for (int i = 0; i < sizeArray; i++) {
        record r = records[i];
        addtime = setTime(r.hour,r.min,r.sec,r.day,r.month,r.year);
        if (difftime(now,mktime(&addtime)) < elapsedTimeInSeconds) {
            if (r.amount < 0)
                totalPeriodExpense -= r.amount;
        }
    }
    return totalPeriodExpense;
}

int getSetBudgetTime(struct tm &setBudgetTime, int &periodSeconds, double &budgetAmount) {
    ifstream fin;
    fin.open("budgeting.txt");
    if(fin.fail()) {
        cout << "budgeting.txt not found!" << endl;
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
            pSeconds = stoi(input) * 86400;
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

void writeBudgetToFile(struct tm setBudgetTime, int periodSeconds, double budgetAmount) {
    ofstream fout;
    fout.open("budgeting.txt", ofstream::trunc);

    if(fout.fail()) {
        cout << "budgeting.txt not found!" << endl;
        exit(1);
    }
    fout << "Day,Month,Year,Hour,Minute,Second,periodSeconds,budgetAmount" << endl;
    fout << setBudgetTime.tm_mday << ',' << setBudgetTime.tm_mon << ',' << setBudgetTime.tm_year << ',' << setBudgetTime.tm_hour << ',' << setBudgetTime.tm_min << ',' << setBudgetTime.tm_sec << ',' << periodSeconds << ',' << budgetAmount << ',';
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
        cout << "Please enter [s] to set the budgeting plan" << (overspent ? " [Warning! You have overspent. Please rebudget]" : "") << endl;
        cout << endl;
        cout << "Budget period: " << (budgetingActive ? to_string(periodSeconds/86400)+" days" : "") << endl;
        cout << "Budget amount: " << (budgetingActive ? to_string(budgetAmount) : "") << endl;
        cout << endl;
        cout << "Time until budget ends: " << (budgetingActive ? remainingTime(remainingTimeInSeconds) : "") << endl;
        cout << "Remaining amount: " << (budgetingActive ? to_string(remainingAmount) : "") << endl;
        for (int i = 0; i < numRow - 12; i++)
            cout << endl;
        cout << "[s] Set New Budget  [x] Exit" << endl;
        printBottomRow(numCol);
        cin >> input;
        if (input == 'x')
            break;
        if (input == 's') {
            if (setBudget(numRow, numCol, setBudgetTime, periodSeconds, budgetAmount) != 0)
                writeBudgetToFile(setBudgetTime, periodSeconds, budgetAmount);
        }
    }
} 
