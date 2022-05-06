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
    int small = min(p->data , q->data);
    int large = max(p->data , q->data);
    while (root != NULL)
    {
        if (root->data > large)
        {
            root = root->left;
        }
        else if (root->data < small)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}

int main(){

}