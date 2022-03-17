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

treenode* takeinput(){
    queue<treenode*> pendingnodes;
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* currentindex = pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter left child data"<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftchild = new treenode(leftchilddata);
            pendingnodes.push(leftchild);
            currentindex->left = leftchild;
        }
        cout<<"enter right child data"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightchild = new treenode(rightchilddata);
            pendingnodes.push(rightchild);
            currentindex->right = rightchild;
        }
    }
    return root;
}

void findsucc(treenode* root , int k , int &succ){
    // int succ = -1;
    if (root == NULL)
    {
        return;
    }
    if (root->data == k)
    {
        if (root->right != NULL)
        {
            treenode* tmp = root->right;
            while (tmp->left != NULL)
            {
                tmp = tmp->left;
            }
            succ = tmp->data;
        }
        // return succ;
    }
    if (root->data > k)
    {
        succ = root->data;
        findsucc(root->left , k , succ);
    }
    else
    {
        findsucc(root->right , k , succ);
    }
}

int main(){
    treenode* root = takeinput();
    int succ = -1;
    findsucc(root , 2 , succ);
    cout<<succ<<endl;
}