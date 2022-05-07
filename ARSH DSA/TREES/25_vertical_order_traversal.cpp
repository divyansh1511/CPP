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

void traverse(treenode* root , int n , int m , map<int , map<int , multiset<int>>> &mp){
    if (root)
    {
        mp[n][m].insert(root->data);
        traverse(root->left , n-1 , m+1 , mp);
        traverse(root->right , n+1 , m+1 , mp);
    }
}

vector<vector<int>> verticaltraversal(treenode* root){
    map<int , map<int , multiset<int>>> mp;
    traverse(root , 0 , 0 , mp);
    vector<vector<int>> ans;
    for(auto it : mp){
        vector<int> v;
        for(auto a : it.second){
            v.insert(v.end() , a.second.begin() , a.second.end());
        }
        ans.push_back(v);
    }
    return ans;
}

int main(){

}