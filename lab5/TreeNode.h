#ifndef _TreeNode_h
#define _TreeNode_h
class TreeNode{
    friend class BinaryDimonTree;
    private:
       int x;
       int y;
       int level;
       TreeNode *right;
       TreeNode *left;
    public:
       TreeNode(int X=0,int Y=0,int Level=1):x(X),y(Y),level(Level),right(nullptr),left(nullptr){};
       int getX(){return x;};
       int getY(){return y;};
};
#endif