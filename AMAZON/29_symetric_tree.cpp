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

bool helper(treenode* left1 , treenode* right1){
    if (left1 == NULL && right1 == NULL)
    {
        return true;
    }
    if (left1 == NULL || right1 == NULL)
    {
        return false;
    }
    return left1->data == right1->data && helper(left1->left , right1->right) && helper(left1->right , right1->left);
}

bool issysmetric(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    return helper(root->left , root->right);
}

int main(){

}