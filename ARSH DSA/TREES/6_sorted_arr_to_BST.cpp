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

treenode* helper(vector<int> &v ,int i , int j){
    if (i > j)
    {
        return NULL;
    }
    int mid = (i+j)/2;
    treenode* root = new treenode(v[mid]);
    root->left = helper(v , i , mid);
    root->right = helper(v , mid+1 , j);
    return root;
}

treenode* converttoBST(vector<int> &v){
    int i = 0 , j = v.size() - 1;
    return helper(v , i , j);
}

int main(){

}