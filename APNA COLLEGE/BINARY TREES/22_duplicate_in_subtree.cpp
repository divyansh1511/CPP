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

string solve(treenode* root , unordered_map<string , int> &mp){
    if (root == NULL)
    {
        return "$";
    }
    string s = "";
    if (root->left == NULL && root->right == NULL)
    {
        s = to_string(root->data);
        return s;
    }
    s = s+to_string(root->data);
    s = s+solve(root->left , mp);
    s = s+solve(root->right , mp);
    mp[s]++;
    return s;
}

bool isduplicate(treenode* root){
    unordered_map<string , int> mp;
    solve(root , mp);
    for(auto it : mp){
        if (it.second >= 2)
        {
            return true;
        }
    }
    return false;
}

int main(){

}