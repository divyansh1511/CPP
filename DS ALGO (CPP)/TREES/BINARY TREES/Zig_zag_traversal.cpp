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
        treenode* currentnode = pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter left child data"<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftchild = new treenode(leftchilddata);
            currentnode->left = leftchild;
            pendingnodes.push(leftchild);
        }
        
        cout<<"enter right child data"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightchild = new treenode(rightchilddata);
            currentnode->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

vector<int> zigzagtrivsal(treenode* root){
    vector<int> v;
    queue<treenode*> q;
    if (root == NULL)
    {
        return v;
    }
    q.push(root);
    int f = 1;
    while (!q.empty())
    {
        vector<int> temp;
        int sz = q.size();
        while (sz--)
        {
            treenode* t = q.front();
            temp.push_back(t->data);
            q.pop();
            if (t->left != NULL)
            {
                q.push(t->left);
            }
            if (t->right != NULL)
            {
                q.push(t->right);
            }
        }
        if (f%2 == 0)
        {
            reverse(temp.begin() , temp.end());
        }
        for (int i = 0; i < temp.size(); i++)
        {
            v.push_back(temp[i]);
        }
        f = !f;
    }
    return v;
}

int main(){
    treenode* t1 = takeinput();
    vector<int> a = zigzagtrivsal(t1);
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
}