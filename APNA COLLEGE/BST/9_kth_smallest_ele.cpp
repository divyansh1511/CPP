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

void inorder(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}

int kthsmallest(treenode* root , int k){
    vector<int> v;
    inorder(root , v);
    return v[k-1];
}

int main(){

}