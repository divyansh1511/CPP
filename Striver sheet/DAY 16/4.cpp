#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isanagram(string a , string s){
    if (a.length() != s.length())
    {
        return false;
    }
    sort(a.begin() , a.end());
    sort(s.begin() , s.end());
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != s[i])
        {
            return false;
        }
    }
    return true;
}

bool isanagram1(string a , string b){
    if (a.length() != b.length())
    {
        return false;
    }
    unordered_map<char , int> mp;
    for (int i = 0; i < a.length(); i++)
    {
        mp[a[i]]++;
        mp[b[i]]--;
    }
    for (auto it : mp)
    {
        if (it.second)
        {
            return false;
        }
    }
    return true;
}

int main(){
    cout<<isanagram("anagram" , "naamarg")<<endl;
    cout<<isanagram1("anagram" , "naamarg")<<endl;
}