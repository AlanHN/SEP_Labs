#ifndef _step_h
#define _step_h
class step{
    struct node{
     int insteps;
     int outsteps;
     node *next;
     node(const int&x,const int&y,node *N=nullptr){
         insteps=x;outsteps=y;next=N;
     }
     node():next(nullptr){}
     ~node(){}
   };
private:
   int size;
   node* top_step;
public:
   step();
   ~step();
   bool isEmpty() const;
   void push(const int &x,const int &y);
   void pop(int &x, int &y);
   int getSize() const;
};
#endif