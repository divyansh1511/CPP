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

treenode* helper(vector<int> pre , vector<int> post , int pi , int po){
    treenode* root = new treenode(pre[pi++]);
    if (root->data != post[po])
    {
        root->left = helper(pre , post , pi , po);
    }
    if (root->data != post[po])
    {
        root->right = helper(pre , post , pi , po);
    }
    po++;
    return root;
}

treenode* construct(vector<int> pre , vector<int> post){
    return helper(pre , post , 0 , 0);
}

int main(){

}