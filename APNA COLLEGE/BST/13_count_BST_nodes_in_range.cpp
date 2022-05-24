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

void helper(treenode *root, int l, int h, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= l && root->data <= h)
    {
        ans++;
    }
    helper(root->left, l, h, ans);
    helper(root->right, l, h, ans);
}

int getCount(treenode *root, int l, int h)
{
    // your code goes here
    int ans = 0;
    helper(root, l, h, ans);
    return ans;
}

int main()
{
}