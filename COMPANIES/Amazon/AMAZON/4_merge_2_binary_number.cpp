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

treenode* merge2tree(treenode* root1 , treenode* root2){
    if (root1 != NULL && root2 != NULL)
    {
        treenode* root = new treenode(root1->data + root2->data);
        root->left = merge2tree(root1->left , root2->right);
        root->right = merge2tree(root1->right , root2->right);
        return root;
    }
    else
    {
        return root1 ? root1 : root2;
    }
}

int main(){

}