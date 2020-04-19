#include "termio.h"
#include"hanoi.h"
#include<iostream>
// Do not delete the following 3 lines
char Termio::buffer[Termio::CANVAS_HEIGHT][Termio::CANVAS_WIDTH + 1];
int Termio::MAX_WIDTH;
int Termio::MAX_HEIGHT;

int main() {

    int diskNum(0),x(0),y(0);

    do{
        cout<<"How many disks do you want?(1~5)";
        cin>>diskNum;
    }while(diskNum<1||diskNum>5);

    hanoi H(diskNum);
    H.show();

    do{
        do{ 
            cout<<"Move a disk.Format:x y";
            cin>>x>>y;
        }while(x<0||x>3||y<0||y>3);

        if(x==0&&y==0){
           H.autohanoi();break;
        }
        else 
           H.move(x,y);
           Termio::Clear();
           H.show();
          
    }while(!H.win());

cout<<"game over"<<endl;
return 0;
}
