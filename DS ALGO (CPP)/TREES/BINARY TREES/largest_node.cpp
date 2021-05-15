#include<iostream>
#include<vector>
#include<queue>
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
    queue<treenode *> pendingnodes;
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

treenode* getlargestnode(treenode* root){
    if (root == NULL)
    {
        return NULL;
    }
    treenode* maxnode = root;
    if (root->left != NULL)
    {
        treenode* largestleftnode = getlargestnode(root->left);
        if (largestleftnode->data > maxnode->data)
        {
            maxnode = largestleftnode;
        }
    }
    if (root->right != NULL)
    {
        treenode* largestrightnode = getlargestnode(root->right);
        if (largestrightnode->data > maxnode->data)
        {
            maxnode = largestrightnode;
        }
    }
    return maxnode;
}

int main(){
    treenode* root = takeinput();
    treenode* result = getlargestnode(root);
    cout<<result->data<<endl;
}