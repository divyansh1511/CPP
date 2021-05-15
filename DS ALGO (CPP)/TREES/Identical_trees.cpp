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

bool isIdentical(treenode* root1 , treenode* root2){
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1->data == root2->data && root1->children.size() == root2->children.size())
    {
        for (int i = 0; i < root1->children.size(); i++)
        {
            if (isIdentical(root1->children[i] , root2->children[i]) == false)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

int main(){
    treenode* root1 = takeinput();
    treenode* root2 = takeinput();
    cout<<isIdentical(root1 , root2)<<endl;
}