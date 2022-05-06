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

bool helper(treenode* ll , treenode* rr){
    if (ll == NULL && rr == NULL)
    {
        return true;
    }
    if (ll == NULL || rr == NULL)
    {
        return false;
    }
    return (ll->data == rr->data) && helper(ll->left , rr->right) && helper(ll->right , rr->left);
}

bool checksymetric(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    return helper(root->left , root->right);
}

int main(){

}