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

int sum = 0;
void helper(treenode* root){
    if (root)
    {
        helper(root->right);
        int temp = root->data;
        root->data += sum;
        sum += temp;
        helper(root->left);
    }
}

treenode* convertBSTtogreater(treenode* root){
    helper(root);
    return root;
}

int main(){

}