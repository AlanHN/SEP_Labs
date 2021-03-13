#ifndef _LISTNODE_H_
#define _LISTNODE_H_
#include<string>

using namespace std;

class ListNode{
    friend class ListBuffer;
private:
    int LineNumber;
    string statement;
    ListNode *next;

public:     
    ListNode():next(NULL){}
    ListNode(int x,const string&y,ListNode *p=NULL):LineNumber(x),statement(y),next(p){}
    ~ListNode(){}
};   
#endif

   