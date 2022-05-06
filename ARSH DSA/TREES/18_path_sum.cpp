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

int sum(treenode* root , int pre , int &su){
    if (!root)
    {
        return 0;
    }
    int curr = root->data + pre;
    return (curr == su) + sum(root->left , curr , su) + sum(root->right , curr , su);
}

int pathsum(treenode* root , int target){
    if (root == NULL)
    {
        return 0;
    }
    return sum(root , 0 , target) + pathsum(root->left , target) + pathsum(root->right , target);
}

int main(){

}