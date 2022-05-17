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

treenode* helper(vector<int> &pre , vector<int> &in , int instart , int inend , int preind){
    if (instart > inend)
    {
        return NULL;
    }
    int index = instart;
    while (in[index] != in[preind])
    {
        index++;
    }
    preind++;
    treenode* newnode = new treenode(in[index]);
    newnode->left = helper(pre , in , instart , index-1 , preind);
    newnode->right = helper(pre , in , index+1 , inend , preind);
    return newnode;
}

treenode* buildtree(vector<int> &pre , vector<int> &in){
    int preind = 0;
    return helper(pre , in , 0 , in.size()-1 , preind);
}

int main(){

}