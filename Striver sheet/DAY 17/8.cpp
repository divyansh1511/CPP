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

void traverse(treenode* root , int x , int y , map<int,map<int,multiset<int>>> &mp){
    if (root)
    {
        mp[x][y].insert(root->data);
        traverse(root->left , x-1 , y+1 , mp);
        traverse(root->right , x+1 , y+1 , mp);
    }
}

vector<vector<int>> verticalTraversals(treenode* root){
    map<int,map<int,multiset<int>>> mp;
    traverse(root , 0 , 0 , mp);
    vector<vector<int>> ans;
    for(auto it : mp){
        vector<int> col;
        for(auto p : it.second){
            col.insert(col.end() , p.second.begin() , p.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main(){

}