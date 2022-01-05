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

void preorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void preorderitr(treenode* root){
    if (root == NULL)
    {
        return;
    }
    stack<treenode*> st;
    treenode* curr = root;
    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL) {
            cout << curr->data << " ";
 
            if (curr->right)
                st.push(curr->right);
 
            curr = curr->left;
        }
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
}

int main(){
    treenode* root = takeinput();
    preorder(root);
    cout<<endl;
    preorderitr(root);
}