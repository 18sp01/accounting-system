#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct record {
    double amount; // amount of money
    int sec, min, hour, day, month, year; // date and time
    std::string type; // type of income/expense (e.g. food, game, salary, etc.)
    std::string account; // account (e.g. cash, bank card, credit card, etc.)
};

void readFromFile(vector<record> &records) {

    ifstream fin;
    fin.open("data.txt");

    if(fin.fail()) {
        cout << "Error in opening file!" << endl;
        exit(1);
    }
    string line;
    int lineCount;
    while (getline(fin, line)) {
        record newRecord;
        fin >> newRecord.amount;
        getline(fin, newRecord.type, ',');
        getline(fin, newRecord.account, ',');
        fin >> newRecord.day >> newRecord.month >> newRecord.year >> newRecord.hour >> newRecord.min;
        records.push_back(newRecord);
    }

    fin.close();
}

void writeToFile(vector<record> records) {
    ofstream fout;
    fout.open("data.txt");

    if(fout.fail()) {
        cout << "Error in opening file!" << endl;
        exit(1);
    }
    
    fout << newRecord.amount << newRecord.type << ',' << newRecord.account << ',' << ' ' << newRecord.day << ' ' << newRecord.month << ' ' << newRecord.year << ' ' << newRecord.hour << ' ' << newRecord.min << endl;
    fout.close();
}

int main () {
    vector<record> records;
    readFromFile(records);
    for (record i : records) {
        cout << "Amount: " << i.amount << " | ";
        cout << "Type: " << i.type << " | ";
        cout << "Account: " << i.account << " | ";
        cout << "Date: " << i.day << " " << i.month << " " << i.year << " " << i.hour << ":" << i.min;
        cout << endl;
    }
    for (record i : records) {
        writeToFile(i);
    }
}