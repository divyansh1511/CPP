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
};

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left) , height(root->right)) + 1;
}

int diameter(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    int leftdiameter = diameter(root->left);
    int rightdiameter = diameter(root->right);

    int leftheight = diameter(root->left);
    int rightheight = diameter(root->right);

    return max(max(leftdiameter , rightdiameter) , leftheight+rightheight+1);
}

int main(){

}