#include<iostream>
#include<unordered_map>
using namespace std;

class trienode{
    public:
    char data;
    unordered_map<char , trienode*> children;
    bool isterminating;
    bool isroot;

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
        if (size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }   
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
        insertword(word.substr(1), child);
    }
    void insert(string word){
        if (!iswordpresent(word))
        {
            insertword(word , root);
            count++;
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
    bool iswordpresent(string word){
        return iswordpresent(word,root);
    }

    bool deleteword(trienode* root , string word){
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
        if (deleteword(child, word.substr(1)))
        {
            root->children.erase(word[0]);
        }
        if (root->isterminating || root->children.size() !=0)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
    void deleteword(string word){
        if (iswordpresent(word))
        {
            deleteword(root ,word);
            count--;
        }
        
    }
};

int main(){
    trie t;
    t.insert("hello");
    t.insert("hey");
    t.insert("some");
    t.insert("so");
    t.insert("me");

    cout<<t.iswordpresent("me")<<endl;
    //cout<<t.iswordpresent("hey")<<endl;
}