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

int solve(treenode* root , int &ans){
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = root->data + solve(root->left , ans);
    int rightsum = root->data + solve(root->right , ans);
    ans = max({ans , leftsum , rightsum , leftsum + rightsum - root->data , root->data});

    return max({leftsum , rightsum , root->data});
}

int maxpathsum(treenode* root){
    int ans = INT_MIN;
    solve(root , ans);
    return ans;
}

int main(){

}