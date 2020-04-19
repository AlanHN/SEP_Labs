#include"step.h"

step::step()
{
   top_step=nullptr;
   size=0;
}

step::~step()
{
    node *tmp;
    while(top_step!=nullptr){
         tmp=top_step;
         top_step=top_step->next;
         delete tmp;
    }
    size=0;
}

bool step::isEmpty() const
{
    return top_step==nullptr;
}

void step::push(const int&x,const int &y)
{
    top_step=new node(x,y,top_step);
    size++;
}

void step::pop(int &x, int &y)
{
    node *tmp=top_step;
    x=tmp->insteps;
    y=tmp->outsteps;
    top_step=top_step->next;
    delete tmp;
    size--;
}


int step::getSize() const
{
    return size;
}