#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
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

bool isBST(treenode* root , int min , int max){
    if (root == NULL)
    {
        return true;
    }
    if (root->data > max || root->data < min)
    {
        return false;
    }
    
    bool leftisBST = isBST(root->left , min , root->data);
    bool rightisBST = isBST(root->right , root->data+1 , max);

    return leftisBST && rightisBST;
}

int main(){
    treenode* root = takeinput();
    cout<<isBST(root , INT_MIN , INT_MAX)<<endl;
}