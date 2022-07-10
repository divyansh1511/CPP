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

int helper(treenode* root , int B , vector<int> &ans){
    if(root == NULL){
        return -1;
    }
    if(root->data == B){
        ans.push_back(root->data);
        return B;
    }
    ans.push_back(root->data);
    int a = helper(root->left , B , ans);
    if(a != -1){
        return a;
    }
    int b = helper(root->right , B , ans);
    if(b != -1){
        return b;
    }
    ans.pop_back();
    return -1;
} 

vector<int> solve(treenode* A, int B) {
    vector<int> ans;
    helper(A , B , ans);
    return ans;
}

int main(){

}