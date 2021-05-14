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
        cout<<"enter no of childs of "<<currentnode->data<<endl;
        int n;
        cin>>n;

        for (int i = 0; i < n; i++)
        {
            int currentchilddata;
            cout<<"enter "<<i<<"th child data"<<currentnode->data<<endl;
            cin>>currentchilddata;
            treenode* childdata = new treenode(currentchilddata);
            currentnode->children.push_back(childdata);
            pendingnodes.push(childdata);
        }
    }
    return root;
}

int height(treenode* root){
    if (root == NULL)
    {
        return 0;    
    }
    int maxheight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int currentheight = height(root->children[i]);
        if (maxheight < currentheight)
        {
            maxheight = currentheight;
        }
    }
    return 1+maxheight;
}

int main(){
    treenode* root = takeinput();
    cout<<height(root)<<endl;
}