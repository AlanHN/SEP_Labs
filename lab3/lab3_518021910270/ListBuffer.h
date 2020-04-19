#pragma once
#include <string>
#include "ListNode.h"

using namespace std;

class ListBuffer {
private: 
     int currentLength;
     int maxLine;

     ListNode *head;

     ListNode* move(int i) const
    {
        ListNode *p=head;
        while(i-->0) p=p->next;
        return p;
    };

public:
    ListBuffer();
    
    void writeToFile(const string &filename) const;
    void clear();
    void showLines() const;
    void deleteLine(int line_idx);
    void insertLine(int line_idx, const string &text);

    ~ListBuffer(){clear();delete head;}
};
