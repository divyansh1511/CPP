#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* links[26];
    bool flag = false;

    bool cointainskey(char ch){
        return links[ch-'a'] != NULL;
    }
    node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch , node* node){
        links[ch-'a'] = node;
    }
    void setend(){
        flag = true;
    }
    bool isend(){
        return flag;
    }
};

class trie{
    node* root;
    public:
    trie(){
        root = new node();
    }

    void insert(string word){
        node* node1 = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node1->cointainskey(word[i]))
            {
                node1->put(word[i] , new node());
            }
            node1 = node1->get(word[i]);
        }
        node1->setend();
    }

    bool checkifPrefixExists(string word){
        bool fl = true;
        node* node1 = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node1->cointainskey(word[i]))
            {
                node1 = node1->get(word[i]);
                if (node1->isend() == false)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

string CompleteString(int n , vector<string> v){
    trie t;
    for(auto it : v){
        t.insert(it);
    }
    string longest = "";
    for(auto it : v){
        if (t.checkifPrefixExists(it))
        {
            if (it.length() > longest.length())
            {
                longest = it;
            }
            else if (it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }
    if (longest == "")
    {
        return "none";
    }
    return longest;
}

int main(){

}