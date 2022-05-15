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

bool isIsomorphic(treenode *root1 , treenode* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    treenode *l1 = root1->left ? root1->left : NULL;
    treenode *r1 = root1->right ? root1->right : NULL;
    treenode *l2 = root2->left ? root2->left : NULL;
    treenode *r2 = root2->right ? root2->right : NULL;
    return (isIsomorphic(l1, l2) && isIsomorphic(r1, r2)) || (isIsomorphic(l1, r2) && isIsomorphic(r1, l2));
}

int main()
{
}