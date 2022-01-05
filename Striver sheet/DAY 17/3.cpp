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

void postorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void postorderitr(treenode* root){
    if (root == NULL)
    {
        return;
    }
    stack<treenode*> st;
    stack<int> s;
    st.push(root);
    while (!st.empty())
    {
        treenode* curr = st.top();
        st.pop();
        s.push(curr->data);
        if (curr->left != NULL)
        {
            st.push(curr->left);
        }
        if (curr->right != NULL)
        {
            st.push(curr->right);
        }
    }
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    treenode* root = takeinput();
    postorder(root);
    cout<<endl;
    postorderitr(root);
}