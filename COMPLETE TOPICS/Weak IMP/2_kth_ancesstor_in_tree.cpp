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

//---------------------1st method-----------using vector-------------------//

int helper(treenode* root , int k , int node , vector<int> &v){
    if(root == NULL){
        return -1;
    }
    if (root->data == node)
    {
        if (v.size() >= k)
        {
            return v[v.size()-k];
        }
    }
    v.push_back(root->data);
    int a = helper(root->left , k , node , v);
    if (a >= 0)
    {
        return a;
    }
    int b = helper(root->right , k , node , v);
    if (b >= 0)
    {
        return b;
    }
    v.pop_back();
    return -1;
}

int kthancesstor(treenode* root , int k , int node){
    vector<int> v;
    return helper(root , k , node , v);
}

//------------------2nd method--------------------without using vector----------------//

treenode* solve(treenode* root , int k , int node){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node)
    {
        return root;
    }
    treenode* leftt = solve(root->left , k , node);
    treenode* rightt = solve(root->right , k , node);

    if (leftt != NULL && rightt == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftt;
    }
    if (leftt == NULL && rightt != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightt;
    }
    return NULL;
}

int kthancesstor1(treenode* root , int k , int node){
    return solve(root , k , node)->data;
}

int main(){

}