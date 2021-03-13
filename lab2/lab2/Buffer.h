#include <string>

using namespace std;

class Buffer {
private:
    static const int MAX_LINE = 512;
    string lines[MAX_LINE];
    int currentLine;
    int maxLine;

public:
    Buffer();
    ~Buffer();

    string moveToLine(int lineNum);
    void moveToPrevLine();

    void writeToFile(const string &filename) const;
    void showLines(int start, int end) const;
    void deleteLines(int start, int end);
    void insertLine(const string &text);
    void appendLine(const string &text);
    int getmaxLine();
    void setCurrendLine(int lineNumber);
};