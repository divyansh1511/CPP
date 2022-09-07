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

int pre = 0;

treenode* binarytogreater(treenode* root){
    if (root->right != NULL)
    {
        binarytogreater(root->right);
    }
    root->data += pre;
    pre = root->data;
    if (root->left != NULL)
    {
        binarytogreater(root->left);
    }
    return root;
}

int main(){

}