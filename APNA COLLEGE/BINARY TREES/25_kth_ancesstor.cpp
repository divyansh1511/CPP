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

treenode* solve(treenode* root , int node , int &k){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node)
    {
        return root;
    }
    treenode* ll = solve(root->left , node , k);
    treenode* rr = solve(root->right , node , k);
    if (ll != NULL && rr == NULL)
    {
        k--;
        if (k == 0)
        {
            k = INT_MAX;
            return root;
        }
        return ll;
    }
    if (ll == NULL && rr != NULL)
    {
        k--;
        if (k == 0)
        {
            k = INT_MAX;
            return root;
        }
        return rr;
    }
    return NULL;
}

int kthancestor(treenode* root , int node , int k){
    treenode* a = solve(root , node , k);
    if (a != NULL)
    {
        return a->data;
    }
    else
    {
        return -1;
    }
    
}

int main(){
    
}