#include <fstream>
#include <iostream>
#include<string>
#include "Buffer.h"

Buffer::Buffer()
{
    currentLine = maxLine = 0;
}
Buffer::~Buffer()
{
}
void Buffer::moveToPrevLine()
{
    if (currentLine <= 1)
        throw out_of_range("Line number out of range");
    currentLine--;
}
string Buffer::moveToLine(int lineNum)
{
    if (lineNum <= 0 || lineNum > maxLine)
        throw out_of_range("Line number out of range");
    currentLine = lineNum;
    return lines[lineNum];
}

void Buffer::writeToFile(const string &filename) const
{
    // write lines to the file and output the number of bytes written.
    ofstream outfile (filename);
    int totalNum=0;
    if(!outfile)
         {cerr<<" no ﬁlename is speciﬁed.";}
    for (int i=1;i<=maxLine;++i)
         {
             outfile<<lines[i]<<endl;
             totalNum+=lines[i].length();
         }
    outfile<<"the number of bytes is:"<<totalNum<<endl;
    outfile.close();
}

void Buffer::showLines(int start, int end) const
{
    //print lines according to the requirement.
    if (start <= 0 || end > maxLine || start > end)
        throw range_error("Number range error");
    for(int i=start;i<=end;i++)
       cout<<i<<'\t'<<lines[i]<<endl;
}

void Buffer::deleteLines(int start, int end)
{
    if (start <= 0 || end > maxLine || start > end)
        throw range_error("Delete range error");
    for (int i = end + 1; i <= maxLine; ++i) {
        lines[i - end - 1 + start] = lines[i];
    }
    maxLine -= end - start + 1;
}

void Buffer::insertLine(const string &text)
{
    //insert a line to current line.
    if (maxLine >= MAX_LINE)
        throw out_of_range("move beyond the file line limit");
    for (int i = maxLine; i >= currentLine; i--) {
        lines[i + 1] = lines[i];
    }
    lines[currentLine] = text;
    maxLine++;
}

void Buffer::appendLine(const string &text)
{
    if (maxLine >= MAX_LINE)
        throw out_of_range("move beyond the file line limit");
    for (int i = maxLine; i > currentLine; i--) {
        lines[i + 1] = lines[i];
    }
    lines[currentLine + 1] = text;
    currentLine++;
    maxLine++;
}

int Buffer::getmaxLine()
{
    return maxLine;
}

void Buffer::setCurrendLine(int lineNumber)
{
    currentLine=lineNumber;
}
