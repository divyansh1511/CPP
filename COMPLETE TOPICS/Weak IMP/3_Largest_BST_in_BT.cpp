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

class Info{
    public:
    int isBST;
    int size;
    int mini;
    int maxi;
};

Info helper(treenode* root , int &ans){
    if (root == NULL)
    {
        return {true , 0 , INT_MIN , INT_MAX};
    }
    Info leftt = helper(root->left , ans);
    Info rightt = helper(root->right , ans);

    Info currnode;
    currnode.size = leftt.size + rightt.size+1;
    currnode.mini = min(root->data , leftt.mini);
    currnode.maxi = max(root->data , rightt.maxi);
    if (leftt.isBST && rightt.isBST && (leftt.maxi < root->data && root->data < rightt.mini))
    {
        currnode.isBST = true;
    }
    else
    {
        currnode.isBST = false;
    }
    if (currnode.isBST)
    {
        ans = max(ans , currnode.isBST);
    }
    return currnode;
}

int largestBST(treenode* root){
    int ans = 0;
    Info temp = helper(root , ans);
    return ans;
}

int main(){

}