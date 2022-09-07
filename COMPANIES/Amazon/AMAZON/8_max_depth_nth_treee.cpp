#include<bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int data;
    vector<treenode*> children;
    treenode(int data){
        this->data = data;
    }
    ~treenode(){
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

int maxDepth(treenode* root) {
    if(root == NULL){
        return 0;
    }
    int count = 1;
    int n = root->children.size();
    int maxcount = 1;
    for(int i=0;i<n;i++){
        count += maxDepth(root->children[i]);
        maxcount = max(count , maxcount);
        count = 1;
    }
    return maxcount;
}

int main(){
    
}