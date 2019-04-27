#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stdInterface.h"
#include "sortRecords.h"
using namespace std;

// Function: reverseArray: reverses the order of items in records
// Inputs: dynamic array records, size of records
// Outputs: records reversed
void reverseArray (record *records, int sizeArray) {
    reverse(records, records+sizeArray);
}

// Structure: sortAmount: contains bool operator that compares amount
struct sortAmount{
    inline bool operator() (record &struct1, record &struct2) {
        return (struct1.amount < struct2.amount);
    }
};

// Function: sortByAmount: sort records by amount
// Inputs: dynamic array records, size of records, bool ascend indicating sorting in ascending or descending order
// Outputs: records sorted by amount
void sortByAmount (record *records, int sizeArray, bool ascend) {
    sort(records, records+sizeArray, sortAmount());
    reverseArray(records, sizeArray);
    if(ascend) {
        reverseArray(records, sizeArray);
    }
}

// Structure: sortType: contains bool operator that compares type
struct sortType{
    inline bool operator() (record &struct1, record &struct2) {
        return (struct1.type < struct2.type);
    }
};

// Function: sortByType: sort records by type
// Inputs: dynamic array records, size of records, bool ascend indicating sorting in ascending or descending order
// Outputs: records sorted by type
void sortByType(record *records, int sizeArray, bool ascend) {
    sort(records, records+sizeArray, sortType());
    reverseArray(records, sizeArray);
    if(ascend) {
        reverseArray(records, sizeArray);
    }
}

// Structure: sortAccount: contains bool operator that compares account
struct sortAccount{
    inline bool operator() (record &struct1, record &struct2) {
        return (struct1.account < struct2.account);
    }
};

// Function: sortByAccount: sort records by account
// Inputs: dynamic array records, size of records, bool ascend indicating sorting in ascending or descending order
// Outputs: records sorted by account
void sortByAccount (record *records, int sizeArray, bool ascend) {
    sort(records, records+sizeArray, sortAccount());
    reverseArray(records, sizeArray);
    if(ascend) {
        reverseArray(records, sizeArray);
    }
}

// Function: compareDate: compare two different dates
// Inputs: reference to two different records
// Outputs: true if struct1 is older than struct2, false otherwise
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

// Function: sortByDate: sort records by date
// Inputs: dynamic array records, size of records, bool ascend indicating sorting in ascending or descending order
// Outputs: records sorted by date
void sortByDate (record *records, int sizeArray, bool ascend) {
    sort(records, records+sizeArray, compareDate);
    reverseArray(records, sizeArray);
    if(ascend) {
        reverseArray(records, sizeArray);
    }
}