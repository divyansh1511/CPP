#include<iostream>
#include<queue>
#include<vector>
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

treenode* takeinput(){
    queue<treenode*> pendingnodes;
    cout<<"enter root data"<<endl;
    int rootdata;
    cin>>rootdata;

    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode* currentnode = pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter no of childs of "<<currentnode->data<<endl;
        int n;
        cin>>n;

        for (int i = 0; i < n; i++)
        {
            int currentchilddata;
            cout<<"enter "<<i<<"th child data "<<currentnode->data<<endl;
            cin>>currentchilddata;
            treenode* childnode = new treenode(currentchilddata);
            currentnode->children.push_back(childnode);
            pendingnodes.push(childnode);
        }
    }
    return root;
}

void replacedepth(treenode* root , int k){
    if (root == NULL)
    {
        return;
    }
    root->data = k;
    for (int i = 0; i < root->children.size(); i++)
    {
        replacedepth(root->children[i] , k+1);
    }
}

void printtree(treenode* root){
    queue<treenode *> pendingnodes;
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode* currentnode = pendingnodes.front();
        pendingnodes.pop();
        string tobeprinted = to_string(currentnode->data)+":";
        for (int i = 0; i < currentnode->children.size(); i++)
        {
            tobeprinted += to_string(currentnode->children[i]->data)+",";
            pendingnodes.push(currentnode->children.at(i));
        }
        cout<<tobeprinted<<endl;
    }
}

int main(){
    treenode* root = takeinput();
    replacedepth(root , 0);
    printtree(root);
}