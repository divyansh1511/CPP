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

treenode* LCA(treenode* root , int n1 , int n2){
    if (root == NULL)
    {
        return root;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    treenode* ln = LCA(root->left , n1 , n2);
    treenode* rn = LCA(root->right , n1 , n2);
    if (ln != NULL && rn != NULL)
    {
        return root;
    }
    if (ln == NULL && rn == NULL)
    {
        return NULL;
    }
    if (ln != NULL)
    {
        return LCA(root->left , n1 , n2);
    }
    return LCA(root->right , n1 , n2);
}

int main(){

}