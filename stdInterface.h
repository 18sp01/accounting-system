struct record {
    double amount; // amount of money
    int sec, min, hour, day, month, year; // date and time
    std::string type; // type of income/expense (e.g. food, game, salary, etc.)
    std::string account; // account (e.g. cash, bank card, credit card, etc.)
    int originalIndex; // keeps track of original index of records when going through filter
};

void updateRecordsSize(record *&records, int &sizeArray, int sizeChange);

void updateIntsSize(int *&ints, int &sizeArray, int sizeChange);

void printTopRow(int numCol);

void printBottomRow(int numCol);