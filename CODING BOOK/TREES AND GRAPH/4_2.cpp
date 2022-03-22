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

treenode* maketree(int arr[] , int i , int j){
    if (i > j)
    {
        return NULL;
    }
    int mid = (i+j)/2;
    treenode* newnode = new treenode(arr[mid]);
    newnode->left = maketree(arr , i , mid-1);
    newnode->right = maketree(arr , mid+1 , j);
    return newnode;
}

int main(){
    
}