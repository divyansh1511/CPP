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
 
void kthdistance(treenode* root , int k , vector<int> &res){
    if (!root || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        res.push_back(root->data);
    }
    kthdistance(root->left , k , res);
    kthdistance(root->right , k , res);
}

int helper(treenode* root , treenode* target , int k , vector<int> &res){
    if (root == NULL || k < 0)
    {
        return -1;
    }
    if (root == target)
    {
        kthdistance(root , k , res);
        return 0;
    }
    int ld = helper(root->left , target , k , res);
    if (ld != -1)
    {
        if (ld+1 > k)
        {
            return -1;
        }
        if (ld+1 == k)
        {
            res.push_back(root->data);
        }
        else
        {
            kthdistance(root->left , k-ld-2 , res);
        }
        return 1+ld;
    }
    int rd = helper(root->right , target , k , res);
    if (rd != -1)
    {
        if (rd+1 > k)
        {
            return -1;
        }
        if (rd+1 == k)
        {
            res.push_back(root->data);
        }
        else
        {
            kthdistance(root->right , k-rd-2 , res);
        }
        return 1+rd;
    }
    return -1;
}

vector<int> distanceatk(treenode* root , treenode* target , int k){
    vector<int> res;
    helper(root , target , k , res);
    return res;
}

int main(){
    
}