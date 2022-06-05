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

void maxwidthhelper(treenode* root , int lvl , int i , unordered_map<int,int>&mini , unordered_map<int,int>&maxi){
    if (root == NULL)
    {
        return;
    }
    if (maxi[lvl])
    {
        maxi[lvl] = max(maxi[lvl] , i);
    }
    else
    {
        maxi[lvl] = i;
    }
    if (mini[lvl])
    {
        mini[lvl] = min(mini[lvl] , i);
    }
    else
    {
        mini[lvl] = i;
    }
    maxwidthhelper(root->left , lvl+1 , 2*i+1 , mini , maxi);
    maxwidthhelper(root->right , lvl+1 , 2*i+2 , mini , maxi);
}

int maxwidth(treenode* root){
    unordered_map<int , int> mini , maxi;
    maxwidthhelper(root , 0 , 0 , mini , maxi);
    int maxx = 0;
    for(auto it : maxi){
        maxx = max(maxx , maxi[it.first] - mini[it.first]+1);
    }
    return maxx;
}

int main(){
    
}