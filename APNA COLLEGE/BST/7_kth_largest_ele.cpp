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

int kth_largest(treenode* root , int k){
    if (root == NULL)
    {
        return 0;
    }
    vector<int> v;
    inorder(root , v);
    int n = v.size();
    return v[n-1-k];
}

int main(){

}