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

int minele(treenode* root){
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root ? root->data : 0;
}

int main(){

}