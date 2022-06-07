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

treenode* fliptree(treenode* root){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }
    treenode* ff = fliptree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = NULL;
    return ff;
}

int main(){

}