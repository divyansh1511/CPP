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

treenode* helper(vector<int> v , int i , int j){
    if (i > j)
    {
        return NULL;
    }
    int mid = (i+j)/2;
    treenode* root = new treenode(v[mid]);
    root->left = helper(v , i , mid-1);
    root->right = helper(v , mid+1 , j);
    return root;
}

treenode* convert(treenode* root){
    vector<int> v;
    inorder(root , v);
    return helper(v , 0 , v.size()-1);
}

int main(){

}