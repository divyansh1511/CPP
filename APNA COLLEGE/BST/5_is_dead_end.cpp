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

void helper(treenode* root , unordered_set<int> &all_nodes , unordered_set<int> &leaf_nodes){
    if (root == NULL)
    {
        return;
    }
    all_nodes.insert(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        leaf_nodes.insert(root->data);
        return;
    }
    helper(root->left , all_nodes , leaf_nodes);
    helper(root->right , all_nodes , leaf_nodes);
}

bool is_dead_end(treenode* root){
    if (root == NULL)
    {
        return false;
    }
    unordered_set<int> all_nodes , leaf_nodes;
    helper(root , all_nodes , leaf_nodes); 
}

int main(){

}