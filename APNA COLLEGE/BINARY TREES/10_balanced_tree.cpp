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

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left) , height(root->right))+1;
}

bool isbalanced(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 && isbalanced(root->left) && isbalanced(root->right))
    {
        return true;
    }
    return false;
}

int main(){

}