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

void helper(treenode* root , int d , map<int , vector<int>> &mp){
    if (root == NULL)
    {
        return;
    }
    mp[d].push_back(root->data);
    helper(root->left , d+1 , mp);
    helper(root->right , d , mp);
}

vector<vector<int>> diagonaltraversal(treenode* root){
    map<int , vector<int>> mp;
    helper(root , 0 , mp);
    vector<vector<int>> ans;
    for(auto it : mp){
        vector<int> v = it.second;
        ans.push_back(v);
    }
    return ans;
}

int main(){

}