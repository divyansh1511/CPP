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

bool checkroot(treenode* root , treenode* temp){
    if (root == NULL && temp == NULL)
    {
        return true;
    }
    if (root == NULL || temp == NULL)
    {
        return false;
    }
    bool leftt = checkroot(root->left , temp->left);
    bool rightt = checkroot(root->right , temp->right);
    return leftt && rightt;
}

bool issubtree(treenode* root , treenode* temp){
    if (root == NULL)
    {
        return false;
    }
    if (checkroot(root , temp))
    {
        return true;
    }
    return checkroot(root->left , temp) || checkroot(root->right , temp);
}

int main(){

}