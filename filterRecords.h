using namespace std;
void filterRecords(int numRow, int numCol, record *&records, int &sizeArray, int page, int usedLines, string &sortParameter, bool &ascend, char category);
bool stringCompare0(char a, char b);
bool stringCompare(string a, string b);
bool checkDateMatch (record record1, record record2);