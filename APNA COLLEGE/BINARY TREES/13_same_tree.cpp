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

bool isSameTree(treenode* root1 , treenode* root2){
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    return (root1->data == root2->data) && isSameTree(root1->left , root2->right) && isSameTree(root1->right , root2->right);
}

int main(){

}