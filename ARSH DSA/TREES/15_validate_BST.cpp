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
    bool l = helper(root->left , mini , root->data);
    bool r = helper(root->right , root->data , maxi);
    return l && r;
}

bool validBST(treenode* root){
    int mini = INT_MIN , maxi = INT_MAX;
    return helper(root , mini , maxi);
}

int main(){

}