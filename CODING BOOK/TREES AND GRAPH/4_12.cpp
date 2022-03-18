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

int sumup(treenode* root , int pre , int targetsum){
    if (root == NULL)
    {
        return;
    }
    int currval = root->data + pre;
    return (targetsum == currval) + sumup(root->left , currval , targetsum) + sumup(root->right , currval , targetsum);
}

int pathsum(treenode* root , int targetsum){
    if(root == NULL){
        return 0;
    }
    return sumup(root , 0 , targetsum) + pathsum(root->left , targetsum) + pathsum(root->right , targetsum);
}

int main(){
    treenode* root = takeinput();
} 