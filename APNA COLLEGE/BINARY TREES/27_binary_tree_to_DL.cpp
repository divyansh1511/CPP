#include <bits/stdc++.h>
using namespace std;

class treenode
{
public:
    int data;
    treenode *left;
    treenode *right;
    treenode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~treenode()
    {
        delete left;
        delete right;
    }
};

void inorder(treenode *root, vector<treenode *> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}
treenode *bToDLL(treenode *root)
{
    // your code here
    vector<treenode *> v;
    inorder(root, v);
    v[0]->left = NULL;
    for (int i = 0; i < v.size() - 1; i++)
    {
        v[i]->right = v[i + 1];
        v[i + 1]->left = v[i];
    }
    v[v.size() - 1]->right = NULL;
    return v[0];
}

int main()
{
}