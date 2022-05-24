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

treenode* construct(int arr[], int l, int h){
    if(l>h) return NULL;
    treenode* root = new treenode(arr[l]);
    int i=l+1;
    while(arr[i]<arr[l] && i<=h) i++;
    root->left = construct(arr, l+1, i-1);
    root->right = construct(arr, i, h);
    return root;
}

treenode* post_order(int pre[], int size)
{
    //code here
    if(size == 0){
        return NULL;
    }
    return construct(pre , 0 , size-1);
}

int main(){

}