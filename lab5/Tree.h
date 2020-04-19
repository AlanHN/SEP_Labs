#include"TreeNode.h"
#ifndef _BinaryDimonTree_H
#define _BinaryDimonTree_H
class BinaryDimonTree{
    private:
       TreeNode *root;
    public:
       BinaryDimonTree():root(nullptr){};
       ~BinaryDimonTree(){clear(root);}
       void insert(int x, int y);
       TreeNode* find_nearest_node(int x, int y);
       bool cmpX(TreeNode &a,TreeNode &b){return a.getX()<b.getX();}//a.x<b.x?
       bool cmpY(TreeNode &a,TreeNode &b){return a.getY()<b.getY();}//a.y<b.y?
       bool cmp(TreeNode &a,TreeNode &b);
       double vdis(TreeNode &a,TreeNode &b);
       double distance(TreeNode &a,TreeNode &b);
       void clear(TreeNode *&t);
       void findnearestnode(TreeNode *goal,TreeNode *curr);
};
#endif