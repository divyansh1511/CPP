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

treenode* insert(treenode* root , int val , treenode* &succ){
    if (root == NULL)
    {
        return root = new treenode(val);
    }
    if (val < root->data)
    {
        succ = root;
        root->left = insert(root->left , val , succ);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right , val , succ);
    }
    return root;
}

void replace(int arr[] , int n){
    treenode* root = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        treenode* succ = NULL;
        root = insert(root , arr[i] , succ);
        if (succ != NULL)
        {
            arr[i] = succ->data;
        }
        else
        {
            arr[i] = -1;
        }
    }
}

int main(){

}