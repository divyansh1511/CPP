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

treenode* LCS(treenode* root , int n1 , int n2){
    if (root == NULL)
    {
        return root;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    treenode* leftt = LCS(root->left , n1 , n2);
    treenode* rightt = LCS(root->right , n1 , n2);
    if (leftt != NULL && rightt != NULL)
    {
        return root;
    }
    if (leftt == NULL && rightt == NULL)
    {
        return NULL;
    }
    if (leftt != NULL)
    {
        return LCS(root->left , n1 , n2);
    }
    return LCS(root->right , n1 , n2);
}

int main(){
    treenode* root = takeinput();
    cout<<LCS(root , 4 , 7)->data<<endl;
}