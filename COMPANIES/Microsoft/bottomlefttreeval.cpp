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

void helper(treenode* root , int &maxdepth , int &leftval , int depth){
    if (root == NULL)
    {
        return;    
    }
    helper(root->left , maxdepth , leftval , depth+1);
    helper(root->right , maxdepth , leftval , depth+1);
    if (depth > maxdepth)
    {
        maxdepth = depth;
        leftval = root->data;
    }
}

int bottomleftnode(treenode* root){
    if(root == NULL){
        return 0;
    }
    int leftval = root->data;
    int maxdepth = 0;
    helper(root , maxdepth , leftval , 0);
    return leftval;
}

int main(){
    treenode* root = takeinput();
    cout<<bottomleftnode(root)<<endl;
}