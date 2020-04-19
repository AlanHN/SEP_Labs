#include "termio.h"
#include "rod.h"
#include "step.h"
#include <iostream>
#ifndef _hanoi_h
#define _hanoi_h
class hanoi{
private:
   int diskNum;
   rod A,B,C;
   step S;
public:
    hanoi(int x){
        diskNum=x;
        for(int i=x;i>0;i--) {
            A.push(i);
        }  
   }

   void show() {
        Termio::ResetBuffer();
        for (int i = 0; i < 40; i++){
            Termio::buffer[6][i] = '-';
        }
        for (int i = 0; i < 7; i++) {
            Termio::buffer[i][5] = '|';
            Termio::buffer[i][20] = '|';
            Termio::buffer[i][35] = '|';
        }
        if(!A.isEmpty()){
        for(int i=0;i<=A.getSize();i++){
            if(A.getdisks()[i]){ 
               for(int j=5-A.getDiskSize(i);j<=5+A.getDiskSize(i);++j)
               Termio::buffer[5-i][j]='*';
            }
            }
        }
        if(!B.isEmpty()){
        for(int i=0;i<=B.getSize();i++){
            if(B.getdisks()[i]){ 
               for(int j=20-B.getDiskSize(i);j<=20+B.getDiskSize(i);++j)
               Termio::buffer[5-i][j]='*';
            }
            }
        }
        if(!C.isEmpty()){
        for(int i=0;i<=C.getSize();i++){
            if(C.getdisks()[i]){ 
               for(int j=35-C.getDiskSize(i);j<=35+C.getDiskSize(i);++j)
               Termio::buffer[5-i][j]='*';
            }
            }
        }
        Termio::Draw();
    }   

   rod *rtrans(int x){
       switch(x){
        case 1: return &A; 
        case 2: return &B; 
        case 3: return &C;
        }
    }

    char ctrans(int x){
        switch (x){
        case 1: return 'A';
        case 2: return 'B';
        case 3: return 'C';
        }
    }

   void move(int x,int y){
        if(rtrans(x)->top()<rtrans(y)->top()){
           rtrans(y)->push(rtrans(x)->pop());
           setStep(x,y);
        }
    }

    void automove(int x,int y){
        rtrans(y)->push(rtrans(x)->pop());
        char out=ctrans(x);
        char in=ctrans(y);
        cout<<"Auto moving "<<out<<"-> "<<in<<endl;
        show();
    }

   void Hanoi(int n,int a,int b,int c){
        if(n==1){
            automove(a,c);
        }
        else{
            Hanoi(n-1,a,c,b);
            automove(a,c);
            Hanoi(n-1,b,a,c);
        }
    }

   void autohanoi(){
        for(int i=0;i<S.getSize();){
            int x,y;
            S.pop(x,y);
            automove(y,x);
        }
        Hanoi(diskNum,1,2,3);
    }

   bool win() const{
         return (A.isEmpty()&&B.isEmpty());
    }

   void setStep(int x,int y){
        S.push(x,y);
    }

};
#endif