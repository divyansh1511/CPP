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
    return 1+max(height(root->left) , height(root->right));
}

int helper(int n){
    int dp[n][n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j || i == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
        if (i == n-1)
        {
            for (int j = 0; j < n; j++)
            {
                sum += dp[i][j];
            }
        }
    }
    return sum;
}

int widthofbt(treenode* root){
    int n = height(root);
    return helper(n);
}

int main(){

}