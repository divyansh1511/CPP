#include <iostream>
#include <queue>
#include <map>
#include <bits/stdc++.h>
#include <stack>
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

treenode *takeinput()
{
    queue<treenode *> pendingnodes;
    cout << "enter root data" << endl;
    int rootdata;
    cin >> rootdata;

    treenode *root = new treenode(rootdata);
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode *currnode = pendingnodes.front();
        pendingnodes.pop();
        cout << "enter left child data" << endl;
        int leftchilddata;
        cin >> leftchilddata;

        if (leftchilddata != -1)
        {
            treenode *leftchild = new treenode(leftchilddata);
            currnode->left = leftchild;
            pendingnodes.push(leftchild);
        }

        cout << "enter right child data" << endl;
        int rightchilddata;
        cin >> rightchilddata;

        if (rightchilddata != -1)
        {
            treenode *rightchild = new treenode(rightchilddata);
            currnode->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

void printlevelwise(treenode *root)
{
    queue<treenode *> pendingnodes;
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        treenode *currnode = pendingnodes.front();
        pendingnodes.pop();
        string tobeprinted = to_string(currnode->data) + ":";

        if (currnode->left != NULL)
        {
            tobeprinted += "L :" + to_string(currnode->left->data) + ",";
            pendingnodes.push(currnode->left);
        }
        else
        {
            tobeprinted += "L:-1";
        }
        if (currnode->right != NULL)
        {
            tobeprinted += "R :" + to_string(currnode->right->data) + ",";
            pendingnodes.push(currnode->right);
        }
        else
        {
            tobeprinted += "R:-1";
        }
        if (tobeprinted[tobeprinted.length() - 1] == ',')
        {
            tobeprinted = tobeprinted.substr(0, tobeprinted.length() - 1);
        }
        cout << tobeprinted << endl;
    }
}

void printrecursion(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    string tobeprinted = to_string(root->data) + ":";
    if (root->left != NULL)
    {
        tobeprinted += to_string(root->left->data) + ",";
    }
    if (root->right != NULL)
    {
        tobeprinted += to_string(root->right->data) + ",";
    }
    cout << tobeprinted << endl;
    printrecursion(root->left);
    printrecursion(root->right);
}

bool findnode(treenode *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    return findnode(root->left, key) || findnode(root->right, key);
}

treenode *getlargest(treenode *root)
{
    if (root == NULL)
    {
        return root;
    }
    treenode *maxnode = root;
    if (root->left != NULL)
    {
        treenode *currnode = getlargest(root->left);
        if (currnode->data > maxnode->data)
        {
            maxnode = currnode;
        }
    }
    if (root->right != NULL)
    {
        treenode *currnode = getlargest(root->right);
        if (currnode->data > maxnode->data)
        {
            maxnode = currnode;
        }
    }
    return maxnode;
}

void mirror(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    treenode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

int height(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftdiameter = diameter(root->left);
    int rightdiameter = diameter(root->right);

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return max(max(leftdiameter, rightdiameter), 1 + leftheight + rightheight);
}

int noofnodesatk(treenode *root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    if (k == 0)
    {
        return 1;
    }
    return noofnodesatk(root->left, k - 1) + noofnodesatk(root->right, k - 1);
}

int width(treenode *root)
{
    int heighttree = height(root);
    if (root == NULL)
    {
        return 0;
    }
    int maxnode = 1;
    for (int i = 0; i < heighttree; i++)
    {
        int currnode = noofnodesatk(root, i);
        if (currnode > maxnode)
        {
            maxnode = currnode;
        }
    }
    return maxnode;
}

void inordered(treenode *root)
{
    if (root == NULL)
    {
        return;
    }

    inordered(root->left);
    cout << root->data << " ";
    inordered(root->right);
}

void inorderiteratie(treenode *root)
{
    stack<treenode *> st;
    treenode *curr = root;

    while (!st.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            cout << curr->data << endl;
            curr = curr->right;
        }
    }
}

void preorder(treenode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void preorderitr(treenode* root){
    stack<treenode*> st;
    treenode* currnode = root;
    while (!st.empty() || currnode != NULL)
    {
        while (currnode != NULL)
        {
            cout<<currnode->data<<" ";
            if (currnode->right != NULL)
            {
                st.push(currnode->right);
            }
            currnode = currnode->left;
        }
        if (!st.empty())
        {
            currnode = st.top();
            st.pop();
        }
    }
}

void postorder(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void leftview(treenode *root)
{
    queue<treenode *> q;
    if (root == NULL)
    {
        return;
    }
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            treenode *temp = q.front();
            q.pop();

            if (i == 1)
            {
                cout << temp->data << " ";
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void rightview(treenode *root)
{
    queue<treenode *> q;
    if (root == NULL)
    {
        return;
    }
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            treenode *temp = q.front();
            q.pop();

            if (n == 0)
            {
                cout << temp->data << " ";
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void topview(treenode *root)
{
    map<int, int> m;
    queue<pair<treenode *, int>> q;
    if (root == NULL)
    {
        return;
    }
    q.push({root, 0});

    while (!q.empty())
    {
        treenode *temp = q.front().first;
        int h = q.front().second;
        q.pop();
        if (m[h] == 0)
        {
            m[h] = temp->data;
        }
        if (temp->left != NULL)
        {
            q.push({temp->left, h - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, h + 1});
        }
    }
    for (auto x : m)
    {
        cout << x.second << endl;
    }
}

void bottomview(treenode *root)
{
    map<int, int> m;
    queue<pair<treenode *, int>> q;
    if (root == NULL)
    {
        return;
    }
    q.push({root, 0});

    while (!q.empty())
    {
        treenode *temp = q.front().first;
        int h = q.front().second;
        q.pop();
        m[h] = temp->data;
        if (temp->left != NULL)
        {
            q.push({temp->left, h - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, h + 1});
        }
    }
    for (auto x : m)
    {
        cout << x.second << endl;
    }
}

//----Vertical traverse 987 leetcode-------------

void traverse(treenode* root , int x , int y , map<int  , map<int , multiset<int>>> &mp){
    if (root)
    {
        mp[x][y].insert(root->data);
        traverse(root->left , x-1 , y+1 , mp);
        traverse(root->right , x+1 , y+1 , mp);
    }
}

vector<vector<int>> verticaltraversal(treenode* root){
    map<int , map<int , multiset<int>>> mp;
    traverse(root , 0 , 0 , mp);
    vector<vector<int>> ans;
    for(auto p : mp){
        vector<int> col;
        for(auto it : p.second){
            col.insert(col.end() , it.second.begin() , it.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
//-----------------------------

//---------leetcode 968-----
bool isBalanced(treenode *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return abs(leftheight - rightheight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

bool checkmirror(treenode *root1, treenode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    return root1->data == root2->data && checkmirror(root1->left, root2->right) && checkmirror(root1->right, root2->left);
}

int sum(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}

bool issumtree(treenode *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return true;
    }
    int ls = sum(root->left);
    int rs = sum(root->right);
    if ((root->data == ls + rs) && issumtree(root->left) && issumtree(root->right))
    {
        return true;
    }
    return false;
}

void sumreplace(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    sumreplace(root->left);
    sumreplace(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

int sumreplace0(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int oldval = root->data;

    root->data = sumreplace0(root->left) + sumreplace0(root->right);

    return root->data + oldval;
}

int leafnode(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL || root->right == NULL)
    {
        return 1;
    }
    return leafnode(root->left) + leafnode(root->right);
}

bool samelevel(treenode *root)
{
    int treeheight = height(root);
    int noofleafnodes = leafnode(root);
    int noofnodes = noofnodesatk(root, treeheight - 1);
    if (noofleafnodes == noofnodes)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int search(int in[], int instart, int inend, int data)
{
    int i = instart;
    while (i <= inend)
    {
        if (in[i] == data)
        {
            return i;
        }
        i++;
    }
    return i;
}

treenode *buildtree(int pre[], int in[], int instart, int inend)
{
    static int preindex = 0;
    if (instart > inend)
    {
        return NULL;
    }

    treenode *root = new treenode(pre[preindex++]);

    if (instart == inend)
    {
        return root;
    }

    int index = (instart + inend)/2;        //----------or search function
    root->left = buildtree(pre, in, instart, index - 1);
    root->right = buildtree(pre, in, index + 1, inend);

    return root;
}

int largestsubtreesum(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lefttree = largestsubtreesum(root->left);
    int righttree = largestsubtreesum(root->right);
    return root->data + lefttree + righttree;
}

bool isIsomorphoic(treenode *root1, treenode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    return (isIsomorphoic(root1->left, root2->left) && isIsomorphoic(root1->right, root2->right)) || (isIsomorphoic(root1->left, root2->right) && isIsomorphoic(root1->right, root2->left));
}

treenode *LCA(treenode *root, int n1, int n2)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    treenode *left = LCA(root->left, n1, n2);
    treenode *right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int findlevel(treenode *root, int k, int level)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return level;
    }
    int left = findlevel(root->left, k, level + 1);
    if (left == -1)
    {
        return findlevel(root->right, k, level + 1);
    }
    return left;
}

int finddistance(treenode *root, int n1, int n2)
{
    treenode *lca = LCA(root, n1, n2);

    int d1 = findlevel(lca, n1, 0);
    int d2 = findlevel(lca, n2, 0);
    return d1 + d2;
}

vector<int> digonaltraversal(treenode *root)
{
    queue<treenode *> q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(root);
    while (!q.empty())
    {
        treenode *temp = q.front();
        q.pop();
        while (temp != NULL)
        {
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

void nodesatk(treenode *root, int k, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        v.push_back(root->data);
    }
    nodesatk(root->left, k - 1, v);
    nodesatk(root->right, k - 1, v);
}
vector<vector<int>> levelOrderBottom(treenode *root)
{
    vector<vector<int>> ans;
    int n = height(root);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> v;
        nodesatk(root, i, v);
        ans.push_back(v);
        v.clear();
    }
    return ans;
}

int main()
{
    treenode *root = takeinput();
    // treenode* root2 = takeinput();
    //printlevelwise(root);
    // printrecursion(root);
    // cout<<findnode(root , 5)<<endl;
    // cout<<getlargest(root)->data<<endl;
    // mirror(root);
    // printlevelwise(root);
    // cout<<diameter(root)<<endl;
    // cout<<width(root)<<endl;
    // inordered(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // leftview(root);
    // cout<<endl;
    // rightview(root);
    // cout<<isBalanced(root)<<endl;
    // cout<<checkmirror(root1 , root2)<<endl;
    //cout<<samelevel(root1)<<endl;
    // int in[] = {4,2,5,1,6,3,7};
    // int pre[] = {1,2,4,5,3,6,7};
    // treenode* root = buildtree(pre , in , 0 , 6);
    // printlevelwise(root);
    // cout<<largestsubtreesum(root)<<endl;
    // cout<<isIsomorphoic(root1 , root2)<<endl;
    // sumreplace0(root1);
    // printlevelwise(root1);
    // cout<<finddistance(root1 , 2 , 7)<<endl;
    // vector<int> a;
    // a = digonaltraversal(root1);
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << endl;
    // }
    // treenode* root = takeinput();
    // vector<vector<int>> v;
    // v = levelOrderBottom(root);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<vector<int>> ans = verticaltraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}