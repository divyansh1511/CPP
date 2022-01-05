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
            pendingnodes.push(leftchild);
            currnode->left = leftchild;
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

void solve(treenode* root , treenode* &head , treenode* &tail , int &f){
    if (root == NULL)
    {
        return;
    }
    solve(root->left , head , tail , f);
    if (f == 0)
    {
        head = root;
        tail = root;
        f = 1;
    }
    else
    {
        tail->right = root;
        tail->right->left = tail;
        tail = tail->right;
    }
    solve(root->right , head , tail , f);
}

treenode* binarytodll(treenode* root){
    treenode* head = NULL;
    treenode* tail = NULL;
    int f = 0;
    solve(root , head , tail , f);
    return head;
}

int main(){
    
}