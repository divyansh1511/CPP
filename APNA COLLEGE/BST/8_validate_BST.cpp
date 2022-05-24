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

bool helper(treenode* root , int mini , int maxi){
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

bool isvalidate(treenode* root){
    return helper(root , INT_MIN , INT_MAX);
}

int main(){

}