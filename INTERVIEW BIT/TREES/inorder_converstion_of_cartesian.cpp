#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
    ~TreeNode(){
        delete left;
        delete right;
    }
};

TreeNode* construct(vector<int> &v,int start,int end)
{
    if(start==end)
    {
        TreeNode* leaf=new TreeNode(v[start]);
        return leaf;
    }
    int maxx=INT_MIN;
    int ind;
    for(int i=start; i<=end; i++)
    {
        if(v[i]>maxx)
        {
            maxx=v[i];
            ind=i;
        }
    }
    TreeNode* root=new TreeNode(maxx);
    if(ind>start)
        root->left=construct(v,start,ind-1);
    if(ind<end)
        root->right=construct(v,ind+1,end);
    return root;
}

TreeNode* buildTree(vector<int> &A) {
    int n=A.size();
    return construct(A,0,n-1);
}

int main(){
    
}