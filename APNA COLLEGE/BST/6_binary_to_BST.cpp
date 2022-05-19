#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
Node *helper(vector<int> &ans, int i, int j)
{
    // int i = 0 , j = ans.size() - 1;
    if (i > j)
    {
        return NULL;
    }
    int mid = (i + j) / 2;
    Node *newnode = new Node(ans[mid]);
    newnode->left = helper(ans, i, mid - 1);
    newnode->right = helper(ans, mid + 1, j);
    return newnode;
}
Node *binaryTreeToBST(Node *root)
{
    // Your code goes here
    if (root == NULL)
    {
        return NULL;
    }
    vector<int> ans;
    inorder(root, ans);
    sort(ans.begin(), ans.end());
    return helper(ans, 0, ans.size() - 1);
}

int main()
{
}