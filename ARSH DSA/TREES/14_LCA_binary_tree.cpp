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

treenode* LCA(treenode* root , treenode* p , treenode* q){
    if (!root || !p || !q)
    {
        return NULL;
    }
    if (root == p || root == q)
    {
        return root;
    }
    treenode* l = LCA(root->left , p , q);
    treenode* r = LCA(root->right , p , q);
    if (l && r)
    {
        return root;
    }
    return l ? l : r;
}

int main(){

}