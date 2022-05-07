#include<bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int data;
    treenode* left;
    treenode* right;
    treenode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~treenode(){
        delete left;
        delete right;
    }
};

int helper(treenode* root , int &total){
    if (root == NULL)
    {
        return 2;
    }
    int leftt = helper(root->left , total) , rightt = helper(root->right , total);
    if (leftt == 0 || rightt == 0)
    {
        total += 1;
        return 1;
    }
    if (leftt == 2 && rightt == 2)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

int mincameraCover(treenode* root){
    int total = 0;
    if (helper(root , total) == 0)
    {
        total += 1;
    }
    return total;
}

int main(){

}