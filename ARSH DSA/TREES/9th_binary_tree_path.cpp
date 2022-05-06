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

void helper(treenode* root , vector<string> &ans , string s){
    if(root->left == NULL && root->right == NULL){
        ans.push_back(s);
        return;
    }
    if(root->left != NULL){
        helper(root->left , ans , s+"->"+to_string(root->left->data));
    }
    if(root->right != NULL){
        helper(root->right , ans , s+"->"+to_string(root->right->data));
    }
}

vector<string> binaryTreePath(treenode* root){
    vector<string> ans;
    if (root == NULL)
    {
        return ans;
    }
    helper(root , ans , to_string(root->data));
    return ans;
}

int main(){

}