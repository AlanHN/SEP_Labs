#include"Tree.h"
#include<cmath>

TreeNode *guess;
double bestDist;

bool BinaryDimonTree::cmp(TreeNode &a,TreeNode &b){
   if(b.level%2)
      return cmpX(a,b);
   else
      return cmpY(a,b);
}

double BinaryDimonTree::vdis(TreeNode &a,TreeNode &b){
   if(b.level%2)
      return abs(a.getX()-b.getX());
   else
      return abs(a.getY()-b.getY());
}

double BinaryDimonTree::distance(TreeNode &a,TreeNode &b){    
   double x= (a.getX()-b.getX())*(a.getX() - b.getX()) + (a.getY()- b.getY()) * (a.getY() - b.getY());    
   return sqrt(x);    
}   

void BinaryDimonTree::clear(TreeNode *&t){
   if(t==nullptr) return;
   clear(t->left);
   clear(t->right);
   delete t;
   t==nullptr;
}

void BinaryDimonTree::insert(int x, int y){
   TreeNode N(x,y);
   TreeNode *tmp=root;
   TreeNode *tmpp=root;
   int n=1;
   if(root==nullptr){
      root=new TreeNode(x,y);return;
   }
   for(;tmp!=nullptr;n++){
      tmpp=tmp;
      if(n%2){
         if(cmpX(N,*tmp))
            tmp=tmp->left;
         else
            tmp=tmp->right;
      }
      else{
         if(cmpY(N,*tmp))
            tmp=tmp->left;
         else
            tmp=tmp->right;
      } 
   }
   if((n-1)%2){
      if(cmpX(N,*tmpp))
            tmpp->left=new TreeNode(x,y,n);
         else
            tmpp->right=new TreeNode(x,y,n);
   }
   else{
      if(cmpY(N,*tmpp))
         tmpp->left=new TreeNode(x,y,n);
      else
         tmpp->right=new TreeNode(x,y,n);
   } 
} 

TreeNode* BinaryDimonTree::find_nearest_node(int x, int y){
   TreeNode *goal=new TreeNode(x,y);
   bestDist=1000000;
   guess=nullptr;
   findnearestnode(goal,root);
   return guess;
}

void BinaryDimonTree::findnearestnode(TreeNode *goal,TreeNode *curr){
   if(curr==nullptr||bestDist==0)  return;
   double dis=distance(*goal,*curr);
   if(dis<=bestDist){
      bestDist=dis;guess=curr;
   }
   if(cmp(*goal,*curr))
      findnearestnode(goal,curr->left);
   else
      findnearestnode(goal,curr->right);
   if(vdis(*goal,*curr)<bestDist){
      if(cmp(*goal,*curr))
         findnearestnode(goal,curr->right);
      else
         findnearestnode(goal,curr->left);
   }
}
