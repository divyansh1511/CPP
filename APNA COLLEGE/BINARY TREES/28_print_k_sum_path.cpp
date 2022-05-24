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

void helper(treenode* root , int k , vector<int> &path){
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    helper(root->left , k , path);
    helper(root->right , k , path);
    int f = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        f += path[i];
        if (f == k)
        {
            for (int j = i; j < path.size(); j++)
            {
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }
    }
    path.pop_back();
}

void printkpath(treenode* root , int k){
    vector<int> path;
    helper(root , k , path);
}

int main(){
    
}