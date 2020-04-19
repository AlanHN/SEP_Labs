#include <fstream>
#include <iostream>
#include "ListBuffer.h"

ListBuffer::ListBuffer()
{
    currentLength=maxLine=0;
    head=new ListNode(0,"");
    return;
}
void ListBuffer::writeToFile(const string &filename) const
{
    ofstream outfile (filename);
    int totalNum=0;
    ListNode *p=head->next;
    if(!outfile)
         {cerr<<" no ﬁlename is speciﬁed.";}
    for (int i=1;i<=currentLength;++i,p=p->next)
         {
             outfile<<p->LineNumber<<'\t'<<p->statement<<endl;
             totalNum+=p->statement.length();
         }
    outfile<<"the number of bytes is:"<<totalNum<<endl;
    outfile.close();
    return;
}
void ListBuffer::clear()
{
    ListNode *p=head->next,*q;
    head->next=NULL;
    while(p!=NULL){
        q=p->next;
        delete p;
        p=q;
    }
    currentLength=0;
    return;
}
void ListBuffer::showLines() const
{
    int i=currentLength;
    ListNode *p=head->next;
    for(;i>0;i--,p=p->next)
       {cout<<p->LineNumber<<'\t'<<p->statement<<endl;}
    return;
}
void ListBuffer::insertLine(int line_idx,const string &text)
{
    if(line_idx>maxLine) 
       {
           ListNode *pos;
           pos=move(currentLength);
           pos->next=new ListNode(line_idx,text);
           maxLine=line_idx;
           currentLength++;
           return;
       }
    else 
        for(ListNode *p=head;p->next!=NULL;p=p->next)
        {
            if (p->LineNumber<line_idx&&p->next->LineNumber>=line_idx)
               {
                if(p->next->LineNumber==line_idx)
                     deleteLine(line_idx);
                p->next=new ListNode(line_idx,text,p->next);
                currentLength++;
                return;
                } 
        }
}
void ListBuffer::deleteLine(int line_idx)
{
    for(ListNode *p=head;p->next!=NULL;p=p->next)
       {
         if(p->next->LineNumber==line_idx)
            {
                 ListNode *delp;
                 delp=p->next;
                 p->next=delp->next;
                 delete delp;
                 --currentLength;
                 return;
            }
       }
}
