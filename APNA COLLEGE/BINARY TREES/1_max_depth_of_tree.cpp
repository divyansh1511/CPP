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

int maxdepth(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return max(maxdepth(root->left) , maxdepth(root->right)) + 1;
}

int main(){

}