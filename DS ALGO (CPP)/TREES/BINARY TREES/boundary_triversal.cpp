#include<iostream>
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

void printleaves(treenode* root){
    if (root == NULL)
    {
        return;
    }
    printleaves(root->left);
    if (root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<endl;
    }
    printleaves(root->right);
}

void printleft(treenode* root){
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        cout<<root->data<<endl;
        printleft(root->left);
    }
    else if (root->right != NULL)
    {
        cout<<root->right<<endl;
        printleft(root->right);
    }
}

void printright(treenode* root){
    if (root == NULL)
    {
        return;
    }
    if (root->right != NULL)
    {
        cout<<root->data<<endl;
        printright(root->right);
    }
    else if (root->left != NULL)
    {
        printright(root->left);
        cout<<root->data<<endl;
    }
}

int main(){
    treenode* root = new treenode(20);
    root->left = new treenode(8);
    root->left->left = new treenode(4);
    root->left->right = new treenode(12);
    root->left->right->left = new treenode(10);
    root->left->right->right = new treenode(14);
    root->right = new treenode(22);
    root->right->right = new treenode(25);
    printleft(root);
    printleaves(root);
    printright(root->right);
}