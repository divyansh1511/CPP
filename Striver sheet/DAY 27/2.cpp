#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* links[26];
    int cntendwith = 0;
    int cntprefix = 0;

    bool containskey(char a){
        return links[a - 'a'] != NULL;
    }
    node* get(char a){
        return links[a - 'a'];
    }
    void put(char a , node* node1){
        links[a-'a'] = node1;
    }
    void increaseEnd(){
        cntendwith++;
    }
    void increasePrefix(){
        cntprefix++;
    }
    void deleteEnd(){
        cntendwith--;
    }
    void reducePrefix(){
        cntprefix--;
    }
    int getEnd(){
        return cntendwith;
    }
    int getprefix(){
        return cntprefix;
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
            if (!node1->containskey(word[i]))
            {
                node1->put(word[i] , new node());
            }
            node1 = node1->get(word[i]);
            node1->increasePrefix();
        }
        node1->increaseEnd();
    }

    int countWordsEqualto(string s){
        node* node1 = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (node1->containskey(s[i]))
            {
                node1 = node1->get(s[i]);
            }
            else
            {
                return 0;
            }
        }
        return node1->getEnd();
    }

    int countwordsstaringwith(string s){
        node* node1 = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (node1->containskey(s[i]))
            {
                node1 = node1->get(s[i]);
            }
            else
            {
                return 0;
            }
        }
        return node1->getprefix();
    }

    void erase(string s){
        node* node1 = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (node1->containskey(s[i]))
            {
                node1 = node1->get(s[i]);
                node1->reducePrefix();
            }
            else
            {
                return;
            }
        }
        node1->deleteEnd();
    }
};

int main(){

}