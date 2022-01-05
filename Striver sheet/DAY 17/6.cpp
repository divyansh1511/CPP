#include<iostream>
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

treenode* takeinput(){
    queue<treenode*> pendingnodes;
    cout<<"enter root data"<<endl;
    int rootdata;
    cin>>rootdata;
    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* currnode = pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter left child data"<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftchild = new treenode(leftchilddata);
            currnode->left = leftchild;
            pendingnodes.push(leftchild);
        }
        cout<<"enter right child data"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightchild = new treenode(rightchilddata);
            currnode->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

void topview(treenode* root){
    if (root == NULL)
    {
        return;
    }
    queue<pair<treenode* , int>> q;
    map<int , int> mp;
    q.push({root , 0});
    while (!q.empty())
    {
        treenode* curr = q.front().first;
        int h = q.front().second;
        q.pop();
        if (mp[h] == 0)
        {
            mp[h] = curr->data;
        }
        if (curr->left != NULL)
        {
            q.push({curr->left , h-1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right , h+1});
        }
    }
    for(auto it : mp){
        cout<<it.second<<" ";
    }
}

int main(){
    treenode* head = takeinput();
    topview(head);
}