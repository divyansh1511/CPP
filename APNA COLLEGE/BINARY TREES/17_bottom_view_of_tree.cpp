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

void bottomview(treenode* root){
    if (root == NULL)
    {
        return;
    }
    map<int , int> mp;
    queue<pair<treenode* , int>> q;
    while (!q.empty())
    {
        treenode* temp = q.front().first;
        int h = q.front().second;
        mp[h] = temp->data;
        if (temp->left != NULL)
        {
            q.push({temp->left , h-1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right , h+1});
        }
    }
    for(auto it : mp){
        cout<<it.second<<" ";
    }
}

int main(){

}