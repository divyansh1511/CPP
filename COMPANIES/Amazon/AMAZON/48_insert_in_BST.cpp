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

treenode* insert(treenode* root , int val){
    treenode* newnode = new treenode(val);
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    if (root->data > val)
    {
        insert(root->left , val);
    }
    if (root->data <= val)
    {
        insert(root->right , val);
    }
}

int main(){
    
}