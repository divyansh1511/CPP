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

int depth(treenode* root){
    if (root == NULL)
    {
        return;
    }
    return max(depth(root->left) , depth(root->right)) + 1;
}

int main(){

}