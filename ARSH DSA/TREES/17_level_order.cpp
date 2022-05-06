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

void noofnodesatk(treenode* root , int k , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        v.push_back(root->data);
        return;
    }
    noofnodesatk(root->left , k-1 , v);
    noofnodesatk(root->right , k-1 , v);
}

vector<vector<int>> levelorder(treenode* root){
    vector<vector<int>> ans;
    int n = height(root);
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        noofnodesatk(root , i , v);
        ans.push_back(v);
    }
    return ans;
}

int main(){

}