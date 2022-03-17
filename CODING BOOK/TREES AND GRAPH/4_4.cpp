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
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* currentindex = pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter left child data"<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftchild = new treenode(leftchilddata);
            pendingnodes.push(leftchild);
            currentindex->left = leftchild;
        }
        cout<<"enter right child data"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightchild = new treenode(rightchilddata);
            pendingnodes.push(rightchild);
            currentindex->right = rightchild;
        }
    }
    return root;
}

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left) , height(root->right)) + 1;
}

bool isBalanced(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return abs(leftheight - rightheight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    treenode* root = takeinput();
    cout<<isBalanced(root)<<endl;
}