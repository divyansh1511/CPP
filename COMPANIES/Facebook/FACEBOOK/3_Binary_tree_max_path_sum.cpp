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

int helper(treenode* root , int &ans){
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = root->data + helper(root->left , ans);
    int rightsum = root->data + helper(root->right , ans);

    ans = max({ans , leftsum , rightsum , leftsum+rightsum-root->data , root->data});

    return max({leftsum , rightsum , root->data});
}

int maxPathsum(treenode* root){
    int ans = INT_MIN;
    helper(root , ans);
    return ans;
}

int main(){

}