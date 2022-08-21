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

string serialize(treenode* root){
    if (root == NULL)
    {
        return "#";
    }
    return to_string(root->data)+","+serialize(root->left)+","+serialize(root->right);
}

int helper(string &s){
    int pos = s.find(',');
    int val = stoi(s.substr(0 , pos));
    s = s.substr(pos+1);
    return val;
}

treenode* mydeserialize(string &s){
    if (s[0] == '#')
    {
        if (s.length() > 1)
        {
            s = s.substr(2);
        }
        return NULL;
    }
    else
    {
        treenode* root = new treenode(helper(s));
        root->left = mydeserialize(s);
        root->right = mydeserialize(s);
        return root;
    }
}

treenode* deserialize(string s){
    return mydeserialize(s);
}

int main(){

}