#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
    int data;
    unordered_map<int , trienode*> children;
    bool isroot;
    bool isterminating;
    trienode(int data){
        this->data = data;
    }
};

class trie{
    trienode* root;
    int count;

    public:
    trie(){
        root = new trienode(' ');
        root->isroot = true;
        count = 0;
    }
    int size(){
        return count;
    }
    bool isempty(){
        return count == 0;
    }

    void insertword(string word , trienode* root){
        if (word.length() == 0)
        {
            root->isterminating = true;
            return;
        }
        trienode* child;
        if (root->children.count(word[0]) > 0)
        {
            child = root->children[word[0]];
        }
        else
        {
            trienode* newnode = new trienode(word[0]);
            root->children[word[0]] = newnode;
            child = newnode;
        }
        insertword(word.substr(1) , child);
    }

    void insert(string s){
        if (!ispresent(s))
        {
            insertword(s , root);
        }
    }
    
    bool iswordpresent(string word , trienode* root){
        if (word.length() == 0)
        {
            return root->isterminating;
        }
        if (root->children.count(word[0]) == 0)
        {
            return false;
        }
        trienode* child = root->children[word[0]];
        return iswordpresent(word.substr(1) , child);
    }

    bool ispresent(string word){
        return iswordpresent(word , root);
    }

    bool deletewordhelper(string word , trienode* root){
        if (word.length() == 0)
        {
            root->isterminating = false;
            if (root->children.size() == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        trienode* child = root->children[word[0]];
        if (deletewordhelper(word.substr(1) , child))
        {
            root->children.erase(word[0]);
        }
        if (root->isterminating || root->children.size() != 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void deleteword(string s){
        if (ispresent(s))
        {
            deletewordhelper(s , root);
            count--;
        }
    }
};

int main(){

}