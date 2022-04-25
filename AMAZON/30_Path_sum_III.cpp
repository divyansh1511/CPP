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

int helper(treenode* root , int prev , int sum){
    if (root == NULL)
    {
        return 0;
    }
    int currsum = prev+root->data;
    return (currsum == sum) + helper(root->left , currsum , sum) + helper(root->right , currsum , sum);
}

int pathsum(treenode* root , int target){
    if (root == NULL)
    {
        return 0;
    }
    return helper(root , 0 , target) + pathsum(root->left , target) + pathsum(root->right , target);
}

int main(){

}