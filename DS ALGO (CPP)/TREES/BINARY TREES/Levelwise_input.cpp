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
        cout<<"enter left child data "<<currentnode->data<<endl;
        int leftchild;
        cin>>leftchild;

        if (leftchild != -1)
        {
            treenode* leftchildnode = new treenode(leftchild);
            currentnode->left = leftchildnode;
            pendingnodes.push(leftchildnode);
        }
        
        cout<<"enter right child data "<<currentnode->data<<endl;
        int rightchild;
        cin>>rightchild;

        if (rightchild != -1)
        {
            treenode* rightchildnode = new treenode(rightchild);
            currentnode->right = rightchildnode;
            pendingnodes.push(rightchildnode);
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
    printtree(root);
}