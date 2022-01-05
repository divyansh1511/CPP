//--------------NOT COMPLETED YET
#include <iostream>
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

treenode *takeinput()
{
    queue<treenode *> pendingnodes;
    cout << "enter root data" << endl;
    int rootdata;
    cin >> rootdata;
    treenode *root = new treenode(rootdata);
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode *currnode = pendingnodes.front();
        pendingnodes.pop();
        cout << "enter left child data" << endl;
        int leftchilddata;
        cin >> leftchilddata;
        if (leftchilddata != -1)
        {
            treenode *leftchild = new treenode(leftchilddata);
            pendingnodes.push(leftchild);
            currnode->left = leftchild;
        }
        cout << "enter right child data" << endl;
        int rightchilddata;
        cin >> rightchilddata;
        if (rightchilddata != -1)
        {
            treenode *rightchild = new treenode(rightchilddata);
            currnode->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

void printlevelwise(treenode *root)
{
    queue<treenode *> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode *currnode = pendingnodes.front();
        pendingnodes.pop();
        string tobeprinted = to_string(currnode->data) + " ";
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
            tobeprinted += "R : -1" + to_string(currnode->right->data) + " ";
        }
        else
        {
            tobeprinted += "R : -1";
        }
        cout << tobeprinted << endl;
    }
}

treenode* helper(vector<int> inorder , int is , int ie , vector<int> postorder , int ps ,int pe , unordered_map<int , int> mp){
    if (is > ie || ps > pe)
    {
        return NULL;
    }
    treenode* root = new treenode(postorder[pe]);
    int inroot = mp[postorder[pe]];
    int numsleft = inroot - is;
    root->left = helper(inorder , is , inroot-1 , postorder , ps , ps+numsleft-1 , mp);
    root->right = helper(inorder ,inroot+1 , ie , postorder , ps+numsleft , pe-1 , mp);
    return root;
}


treenode *buildtree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> order;
    for (int i = 0; i < inorder.size(); i++)
        order[inorder[i]] = i;
    
    return helper(inorder , 0 , inorder.size() , postorder , 0 , postorder.size() , order);
}

int main()
{
    vector<int> in = {4, 2, 5, 1, 6, 3, 7};
    vector<int> post = {4, 5, 2, 6, 7, 3, 1};
    treenode *root = buildtree(post, in);
    printlevelwise(root);
}