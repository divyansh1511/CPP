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

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left) , height(root->right)) + 1;
}

void helper(treenode* root , int k , int &sum){
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        sum += root->data;
    }
    helper(root->left , k-1 , sum);
    helper(root->right , k-1 , sum);
}

int maxlevel(treenode* root){
    int n = height(root);
    int sum = INT_MIN;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        helper(root , i , sum);
        if (a > sum)
        {
            sum = a;
            j = i;
        }
    }
    return j+1;
}

int main(){

}