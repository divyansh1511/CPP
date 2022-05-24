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

string solve(treenode* root , vector<treenode*> &v , unordered_map<string , int> &mp){
    if(root == NULL){
        return "";
    }
    string ll = solve(root->left , v , mp);
    string rr = solve(root->right , v , mp);
    string ans = to_string(root->data) + "$" + ll + "$" + rr;

    if (mp[ans] == 1)
    {
        v.push_back(root);
    }
    mp[ans]++;
    return ans;
}

vector<treenode*> duplicatetree(treenode* root){
    vector<treenode*> v;
    unordered_map<string , int> mp;
    solve(root , v , mp);
    return v;
}

int main(){

}