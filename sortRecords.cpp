#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stdInterface.h"
#include "sortRecords.h"
using namespace std;

void reverseVector (record *records, int sizeArray) {
    reverse(records, records+sizeArray);
}

struct sortAmount{
    inline bool operator() (record &struct1, record &struct2) {
        return (struct1.amount < struct2.amount);
    }
};

void sortByAmount (record *records, int sizeArray, bool ascend) {
    sort(records, records+sizeArray, sortAmount());
    reverseVector(records, sizeArray);
    if(ascend) {
        reverseVector(records, sizeArray);
    }
}

struct sortType{
    inline bool operator() (record &struct1, record &struct2) {
        return (struct1.type < struct2.type);
    }
};

void sortByType(record *records, int sizeArray, bool ascend) {
    sort(records, records+sizeArray, sortType());
    reverseVector(records, sizeArray);
    if(ascend) {
        reverseVector(records, sizeArray);
    }
}

struct sortAccount{
    inline bool operator() (record &struct1, record &struct2) {
        return (struct1.account < struct2.account);
    }
};

void sortByAccount (record *records, int sizeArray, bool ascend) {
    sort(records, records+sizeArray, sortAccount());
    reverseVector(records, sizeArray);
    if(ascend) {
        reverseVector(records, sizeArray);
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

void sortByDate (record *records, int sizeArray, bool ascend) {
    sort(records, records+sizeArray, compareDate);
    reverseVector(records, sizeArray);
    if(ascend) {
        reverseVector(records, sizeArray);
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