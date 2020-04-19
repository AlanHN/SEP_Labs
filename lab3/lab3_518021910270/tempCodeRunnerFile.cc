    int i=currentLength;
    ListNode *p=head->next;
    for(;i>0;i--,p=p->next)
       {cout<<p->LineNumber<<'\t'<<p->statement<<endl;}
    return;