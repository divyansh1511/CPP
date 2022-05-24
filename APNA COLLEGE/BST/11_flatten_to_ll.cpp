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

void inorder(treenode* root , treenode* &tmp){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left , tmp);
    tmp->left = NULL;
    tmp->right = root;
    tmp = root;
    inorder(root->right , tmp);
}

treenode* flatten(treenode* root){
    treenode* dmy = new treenode(-1);
    treenode* tmp = dmy;

    inorder(root , tmp);
    tmp->left = NULL;
    tmp->right = NULL;
    return dmy->right;
}

int main(){
    
}