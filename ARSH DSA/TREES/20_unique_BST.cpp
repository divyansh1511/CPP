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

int numtrees(int n){
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            dp[i] = dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){

}