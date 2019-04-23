void filterRecords(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, std::string &sortParameter, bool ascend, char category);
bool stringCompare0(char a, char b);
bool stringCompare(std::string a, std::string b);
bool checkDateMatch (record record1, record record2);