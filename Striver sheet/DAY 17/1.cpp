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

void printlevelwise(treenode* root){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* currnode = pendingnodes.front();
        pendingnodes.pop();
        string tobeprinted = to_string(currnode->data)+" ";
        if (currnode->left != NULL)
        {
            tobeprinted += "L :" + to_string(currnode->left->data) + " ";
            pendingnodes.push(currnode->left);
        }
        else
        {
            tobeprinted += "L : -1";
        }
        if (currnode->right != NULL)
        {
            tobeprinted += "R : -1" + to_string(currnode->right->data)+" ";
        }
        else
        {
            tobeprinted += "R : -1";
        }
        cout<<tobeprinted<<endl;
    }
}

void inorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void inorderitr(treenode* root){
    stack<treenode*> st;
    treenode* curr = root;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            curr = st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }   
    }
}

int main(){
    treenode* root = takeinput();
    inorder(root);
    cout<<endl;
    inorderitr(root);
}