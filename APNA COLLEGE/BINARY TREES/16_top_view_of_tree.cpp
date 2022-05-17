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
};

void topview(treenode* root){
    queue<pair<treenode* , int>> q;
    map<int , int> mp;
    q.push({root , 0});
    while (!q.empty())
    {
        treenode* temp = q.front().first;
        int h = q.front().second;
        q.pop();
        if (mp[h] == 0)
        {
            mp[h] = temp->data;
        }
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