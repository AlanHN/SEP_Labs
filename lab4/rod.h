#ifndef _rod_h
#define _rod_h
class rod{
private:
   int *disks;
   int top_disk;
public:
   rod();
   ~rod();
   bool isEmpty() const;
   void push(const int &x);
   int pop();
   int top() const;
   int* getdisks() const;
   int getDiskSize(int i) const;
   int getSize();
};
#endif