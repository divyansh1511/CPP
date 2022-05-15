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

int helper(treenode* &root){
    if (root == NULL)
    {
        return 0;
    }
    int oldval = root->data;
    root->data = helper(root->left) + helper(root->right);
    return root->data  + oldval;
}

void to_sum_tree(treenode* root){
    helper(root);
}

int main(){

}