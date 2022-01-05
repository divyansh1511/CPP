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

treenode* buildtree(int pre[] , int in[] , int instart , int inend){
    static int pporder = 0;
    if (instart > inend)
    {
        return NULL;
    }
    treenode* root = new treenode(pre[pporder++]);
    if (instart == inend)
    {
        return root;
    }
    int index = (instart + inend)/2;
    root->left = buildtree(pre , in , instart , index-1);
    root->right = buildtree(pre , in , index+1 , inend);
    return root;
}

int main(){
    int in[] = {4,2,5,1,6,3,7};
    int pre[] = {1,2,4,5,3,6,7};
    treenode* root = buildtree(pre , in , 0 , 6);
}