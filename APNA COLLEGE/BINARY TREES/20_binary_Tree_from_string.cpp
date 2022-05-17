#include <bits/stdc++.h>
using namespace std;

class treenode
{
public:
    int data;
    treenode *left;
    treenode *right;
    treenode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~treenode()
    {
        delete left;
        delete right;
    }
};

int findIndex(string str, int si, int ei)
{
    if (si > ei)
        return -1;
    stack<char> s;
    for (int i = si; i <= ei; i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
                if (s.empty())
                    return i;
            }
        }
    }
    return -1;
}

treenode *stringtotree(string str, int si, int en)
{
    if (si > en)
    {
        return NULL;
    }
    treenode *root = new treenode(str[si] - '0');
    int index = -1;
    if (si + 1 <= en && str[si] + 1 == '(')
    {
        index = findIndex(str, si + 1, en);
    }
    if (index != -1)
    {
        root->left = stringtotree(str , si+2 , index-1);
        root->right = stringtotree(str , index+2 , en-1);
    }
    return root;
}

int main()
{
}