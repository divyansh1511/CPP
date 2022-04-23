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

int convert(vector<int> v){
    int n = 0;
    for (int i = 0; i < v.size(); i++)
    {
        n = n*2 + v[i];
    }
    return n;
}

void helper(treenode* root , vector<int> v , int &ans){
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    if (root->left == NULL && root->right == NULL)  
    {
        ans += convert(v);
    }
    helper(root->left , v , ans);
    helper(root->right , v , ans);
}

int sumroottoleaf(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    vector<int> v;
    int ans = 0;
    helper(root , v , ans);
    return ans;
}

int main(){

}