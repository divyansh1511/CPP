#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* links[26];
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch , Node* node){
        links[ch-'a'] = node;
    }
};

int countDistinctSubstring(string s){
    int cnt = 0;
    Node* root = new Node();
    for (int i = 0; i < s.length(); i++)
    {
        Node* node = root;
        for (int j = i; j < s.length(); j++)
        {
            if (!node->containsKey(s[i]))
            {
                cnt++;
                node->put(s[i] , new Node());
            }
            node = node->get(s[i]);
        }
    }
    return cnt+1;
}

int main(){

}