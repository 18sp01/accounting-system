#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stdInterface.h"
#include "sortRecords.h"
using namespace std;

void reverseVector (vector<record> &records) {
    reverse(records.begin(), records.end());
}

struct sortAmount{
    inline bool operator() (record &struct1, record &struct2) {
        return (struct1.amount < struct2.amount);
    }
};

void sortByAmount (vector<record> &records, bool ascend) {
    sort(records.begin(), records.end(), sortAmount());
    reverseVector(records);
    if(ascend) {
        reverseVector(records);
    }
}

struct sortType{
    inline bool operator() (record &struct1, record &struct2) {
        return (struct1.type < struct2.type);
    }
};

void sortByType(vector<record> &records, bool ascend) {
    sort(records.begin(), records.end(), sortType());
    reverseVector(records);
    if(ascend) {
        reverseVector(records);
    }
}

struct sortAccount{
    inline bool operator() (record &struct1, record &struct2) {
        return (struct1.account < struct2.account);
    }
};

void sortByAccount (vector<record> &records, bool ascend) {
    sort(records.begin(), records.end(), sortAccount());
    reverseVector(records);
    if(ascend) {
        reverseVector(records);
    }
}

bool compareDate(record &struct1, record &struct2) {
    if (struct1.year < struct2.year) {
        return true;
    }
    if (struct1.year == struct2.year && struct1.month < struct2.month) {
        return true;
    }
    if (struct1.year == struct2.year && struct1.month == struct2.month && struct1.day < struct2.day) {
        return true;
    }
    if (struct1.year == struct2.year && struct1.month == struct2.month && struct1.day == struct2.day && struct1.hour < struct2.hour) {
        return true;
    }
    if (struct1.year == struct2.year && struct1.month == struct2.month && struct1.day == struct2.day && struct1.hour == struct2.hour && struct1.min < struct2.min) {
        return true;
    }
    return false;
}

void sortByDate (vector<record> &records, bool ascend) {
    sort(records.begin(), records.end(), compareDate);
    reverseVector(records);
    if(ascend) {
        reverseVector(records);
    }
}
/*
void sortVector (vector<record> &records, string sortParameter, bool &ascend) {
    if (sortParameter == "Amount")
        sortByAmount(records,ascend);
    if (sortParameter == "Type")
        sortByType(records,ascend);
    if (sortParameter == "Account")
        sortByAccount(records,ascend);
    if (sortParameter == "Date")
        sortByDate(records,ascend);
}
*/