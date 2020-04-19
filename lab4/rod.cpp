#include"rod.h"

rod::rod()
{
    disks=new int[5];
    for(int i=0;i<5;++i)
     {disks[i]=0;}
    top_disk=-1;
}

rod::~rod()
{
    delete[]disks;
}

bool rod::isEmpty() const
{
    return top_disk==-1;
}

void rod::push(const int&x)
{
    disks[++top_disk]=x;
}

int rod::pop()
{
    return disks[top_disk--];
}

int rod::top() const
{
    if(top_disk==-1) 
       return 6;
    else
       return disks[top_disk];
}

int* rod::getdisks() const
{
  return disks;
}

int rod::getDiskSize(int i) const
{
    return disks[i];
}

int rod::getSize()
{
    return top_disk;
}