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
            treenode* rigthchild = new treenode(rightchilddata);
            currnode->right = rigthchild;
            pendingnodes.push(rigthchild);
        }
    }
    return root;
}

bool checksubtreehelper(treenode* root , treenode* subtree){
    if (root == NULL && subtree == NULL)
    {
        return true;
    }
    if (root == NULL || subtree == NULL)
    {
        return false;
    }
    if (root->data != subtree->data)
    {
        return false;
    }
    return checksubtreehelper(root->left , subtree->left) && checksubtreehelper(root->right , subtree->right);
}

bool checksubtree(treenode* root , treenode* subtree){
    if (root == NULL)
    {
        return false;
    }
    if (checksubtreehelper(root , subtree))
    {
        return true;
    }
    return checksubtree(root->left , subtree) || checksubtree(root->right , subtree);
}

int main(){
    treenode* root = takeinput();
    treenode* subtree = takeinput();
    cout<<checksubtree(root , subtree)<<endl; 
} 