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

void leftele(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    if (root->left)
    {
        v.push_back(root->data);
        leftele(root->left , v);
    }
    else if (root->right)
    {
        v.push_back(root->data);
        leftele(root->right , v);
    }
}

void rightele(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    if (root->right)
    {
        rightele(root->right , v);
        v.push_back(root->data);
    }
    else if (root->left)
    {
        rightele(root->right , v);
        v.push_back(root->data);
    }
}

void leafnodes(treenode* root , vector<int>&v){
    if (root == NULL)
    {
        return;
    }
    leafnodes(root->left , v);
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->data);
        return;
    }
    leafnodes(root->right , v);
}

vector<int> BoundaryTraversal(treenode* root){
    vector<int> v;
    v.push_back(root->data);
    leftele(root->left , v);
    rightele(root->right , v);

}

int main(){

}