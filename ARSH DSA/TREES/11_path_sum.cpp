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

bool haspathsum(treenode* root , int sum){
    if (root == NULL)
    {
        return false;
    }
    if (root->data == sum && root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return haspathsum(root->left , sum - root->data) || haspathsum(root->right , sum - root->data);
}

int main(){

}