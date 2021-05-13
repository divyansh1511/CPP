#include<iostream>
#include<vector>
#include<queue>
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
    queue<treenode *> pendingnodes;
    cout<<"enter root data"<<endl;
    int rootdata;
    cin>>rootdata;

    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode* currentnode = pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter no of child data of"<<currentnode->data<<endl;
        int n;
        cin>>n;

        for (int i = 0; i < n; i++)
        {
            int currentchilddata;
            cout<<"enter "<<i<<"th child data of "<<currentnode->data<<endl;
            cin>>currentchilddata;
            treenode* childnode = new treenode(currentchilddata);
            currentnode->children.push_back(childnode);
            pendingnodes.push(childnode);
        }
    }
    return root;
}

void printtree(treenode* root){
    if (root == NULL)
    {
        return;
    }
    string tobeprinted = to_string(root->data)+":";
    for (int i = 0; i < root->children.size(); i++)
    {
        tobeprinted += to_string(root->children[i]->data)+",";
    }
    cout<<tobeprinted<<endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printtree(root->children[i]);
    }
}

int main(){
    treenode* root = takeinput();
    printtree(root);
} 