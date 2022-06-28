#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
    char data;
    unordered_map<char , trienode*> children;
    bool isroot;
    bool isterminating;

    trienode(char data){
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
        return size() == 0;
    }

    bool wordpresenthelper(string  word , trienode* root){
        if (word.length() == 0)
        {
            return root->isterminating;
        }
        if (root->children.count(word[0]) == 0)
        {
            return false;
        }
        trienode* child = root->children[word[0]];
        return wordpresenthelper(word.substr(1) , child);
    }
    bool iswordpresent(string word){
        return wordpresenthelper(word , root);
    }

    void inserthelper(string word , trienode* root){
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
        inserthelper(word.substr(1) , child);
    }

    void insert(string word){
        if (!iswordpresent(word))
        {
            inserthelper(word , root);
            count++;
        }
    }

    bool deletewordhelper(string word , trienode* root){
        if (word.length() == 0)
        {
            root->isterminating = false;
            return root->children.size() == 0;
        }
        trienode* child = root->children[word[0]];
        if (deletewordhelper(word.substr(1) , child))
        {
            root->children.erase(word[0]);
        }
        return root->isterminating || root->children.size();
    }

    void deleteword(string word){
        if (!iswordpresent(word))
        {
            deletewordhelper(word , root);
            count--;
        }
    }
};

int main(){

}