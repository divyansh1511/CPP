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

bool check(treenode* root , treenode* subroot){
    if (root == NULL && subroot == NULL)
    {
        return true;
    }
    if (root == NULL || subroot == NULL)
    {
        return false;
    }
    if (root->data != subroot->data)
    {
        return false;
    }
    bool a1 = check(root->left , subroot->left);
    bool a2 = check(root->right , subroot->right);
    return a1 && a2;
}

bool isSubtree(treenode* root , treenode* subroot){
    if (!root)
    {
        return false;
    }
    if (check(root , subroot))
    {
        return true;
    }
    return isSubtree(root->left , subroot) || isSubtree(root->right , subroot);
}

int main(){

}