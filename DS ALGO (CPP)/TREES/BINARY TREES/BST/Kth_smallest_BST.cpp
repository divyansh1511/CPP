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

int countnode(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return 1+countnode(root->left)+countnode(root->right);
}

int kthsmallest(treenode* root , int k){
    if (root == NULL)
    {
        return -1;
    }
    int leftcount = countnode(root->left);
    if (leftcount == k-1)
    {
        cout<<root->data<<endl;
    }
    if (leftcount > k-1)
    {
        return kthsmallest(root->left , k);
    }
    else
    {
        return kthsmallest(root->right , k-leftcount-1);
    }
}

int main(){
    treenode* root = takeinput();
    kthsmallest(root , 2);
}