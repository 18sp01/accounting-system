#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "stdInterface.h"
#include "fromtoFile.h"
using namespace std;

void readFromFile(vector<record> &records) {
    ifstream fin;
    fin.open("data.txt");

    if(fin.fail()) {
        cout << "Error in opening file!" << endl;
        exit(1);
    }

    bool first = true;
    string line;
    string amount, type, account, day, month, year, hour, min;
    while (getline(fin, line)) {
        getline(fin, amount, ',');
        getline(fin, type, ',');
        getline(fin, account, ',');
        getline(fin, day, ',');
        getline(fin, month, ',');
        getline(fin, year, ',');
        getline(fin, hour, ',');
        getline(fin, min, ',');
        
        record newRecord;
        double d = stod(amount);
        newRecord.amount = d;
        newRecord.type = type;
        newRecord.account = account;
        newRecord.day = stoi(day);
        newRecord.month = stoi(month);
        newRecord.year = stoi(year);
        newRecord.hour = stoi(hour);
        newRecord.min = stoi(min);
        records.push_back(newRecord);
    }

    fin.close();
}

void writeToFile(vector<record> records) {
    ofstream fout;
    fout.open("data.txt", ofstream::trunc);

    if(fout.fail()) {
        cout << "Error in opening file!" << endl;
        exit(1);
    }
    fout << "Amount,Type,Account,Day,Month,Year,Hour,Minutes" << endl;
    for (int i = 0; i < records.size(); i++) {
        if (i != 0)
            fout << endl;
        fout << records[i].amount << ',' << records[i].type << ',' << records[i].account << ',' << records[i].day << ',' << records[i].month << ',' << records[i].year << ',' << records[i].hour << ',' << records[i].min << ',';
    }
    fout.close();
}