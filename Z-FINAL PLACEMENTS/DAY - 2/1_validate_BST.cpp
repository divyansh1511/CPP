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
    }
    ~treenode(){
        delete left;
        delete right;
    }
};

bool helper(treenode* root , int maxi , int mini){
    if (root == NULL)
    {
        return true;
    }
    if (root->data < mini || root->data > maxi)
    {
        return false;
    }
    return helper(root->left , mini , root->data) && helper(root->right , root->data , maxi);
}

bool validateBST(treenode* root){
    return helper(root , INT_MAX , INT_MIN);
}

int main(){

}