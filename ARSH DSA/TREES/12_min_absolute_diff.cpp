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

int getmindiff(treenode* root){
    int min_diff = INT_MAX , val = -1;
    if (root->left != NULL)
    {
        getmindiff(root->left);
    }
    if (val >= 0)
    {
        min_diff = min(min_diff , root->data - val);
    }
    val = root->data;
    if (root->right != NULL)
    {
        getmindiff(root->right);
    }
    return min_diff;
}

int main(){

}