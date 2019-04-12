#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stdInterface.h"
using namespace std;

void readFromFile(vector<record> &records) {
    char filename[80] = "input_data.txt";
    ifstream fin;
    fin.open(filename);

    if(fin.fail) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

record newRecord;


// Amount Type Account Day Month Year Hour Min

//100 Dinner, Cash, 2 3 2019 20 24
//9998, Game Card, Credit Card, 23, 4, 2019, 14, 35,
while (getline(fin, , ',')) {

}
    fin >> newRecord.amount;
    getline(fin, newRecord.type, ',');
    getline(fin, newRecord.account, ',');
    fin >> newRecord.day >> newRecord.month >> newRecord.year >> newRecord.hour >> newRecord.min;
    fin.close();

    records.push_back(newRecord);
}

void writeToFile() {

}
