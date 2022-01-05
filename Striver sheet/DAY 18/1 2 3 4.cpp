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

//-------------------------------------------------------------

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left) , height(root->right));
}

//--------------------------------------------------------

void noofnodes(treenode* root , int k , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        v.push_back(root->data);
    }
    noofnodes(root->left , k-1 , v);
    noofnodes(root->right , k-1 , v);
}

vector<vector<int>> levelwise(treenode* root){
    vector<vector<int>> ans;
    int n = height(root);
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        noofnodes(root , i , v);
        ans.push_back(v);
    }
    return ans;
}

//-----------------------------------------------------------------------------

int diameter(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);
    return max(max(ld , rd) , 1+leftheight+rightheight);
}
//-----------------------------------------------------------------------

bool checkbinarytree(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return abs(leftheight - rightheight) <= 1 && checkbinarytree(root->left) && checkbinarytree(root->right);
}

//-------------------------------------------------------------------------

int main(){
    treenode* root = takeinput();
    vector<vector<int>> ans = levelwise(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}