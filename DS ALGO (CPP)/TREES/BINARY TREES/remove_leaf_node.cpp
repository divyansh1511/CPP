#include<iostream>
#include<queue>
#include<vector>
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

        cout<<"enter left child data of "<<currentnode->data<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftnode = new treenode(leftchilddata);
            currentnode->left = leftnode;
            pendingnodes.push(leftnode);
        }
        
        cout<<"enter right child data of "<<currentnode->data<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightnode = new treenode(rightchilddata);
            currentnode->right = rightnode;
            pendingnodes.push(rightnode);
        }
    }
    return root;
}

bool isleaf(treenode* root){
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
}

treenode* removeleafnode(treenode* root){
    if (root->left != NULL)
    {
        if (isleaf(root->left))
        {
            root->left = NULL;
        }
        else
        {
            removeleafnode(root->left);
        }
    }
    
    if (root->right != NULL)
    {
        if (isleaf(root->right))
        {
            root->right = NULL;
        }
        else
        {
            removeleafnode(root->right);
        }
    }
    return root;
}

void printtree(treenode* root){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode* currentnode = pendingnodes.front();
        pendingnodes.pop();
        string tobeprinted = to_string(currentnode->data)+":";

        if (currentnode->left != NULL)
        {
            tobeprinted += "L:"+to_string(currentnode->left->data)+",";
            pendingnodes.push(currentnode->left);
        }
        else
        {
            tobeprinted += "L:-1";
        }
        
        if (currentnode->right != NULL)
        {
            tobeprinted += "R:"+to_string(currentnode->right->data)+",";
            pendingnodes.push(currentnode->right);
        }
        else
        {
            tobeprinted += "R:-1";
        }
        cout<<tobeprinted<<endl;
    }
}

int main(){
    treenode* root = takeinput();
    treenode* result = removeleafnode(root);
    printtree(result);
}