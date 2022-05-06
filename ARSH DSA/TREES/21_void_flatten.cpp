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

void flatten(treenode* root){
    while (root != NULL)
    {
        if (root->left != NULL && root->right != NULL)
        {
            treenode* tt = root->left;
            while (tt->right != NULL)
            {
                tt = tt->right;
            }
            tt->right = root->right;
        }
        if (root->left != NULL)
        {
            root->right = root->left;
        }
        root->left = NULL;
        root = root->right;
    }
}

int main(){

}