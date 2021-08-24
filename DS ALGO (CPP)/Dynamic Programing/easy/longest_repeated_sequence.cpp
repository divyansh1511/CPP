#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string solve(string s){
    map<char , int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        if (mp[s[i]] == 0)
        {
            mp[s[i]] = 1;
        }
        else
        {
            mp[s[i]]++;
        }
    }
    string a = "";
    for (auto i : mp)
    {
        if (i.second > 1)
        {
            a += i.first;
        }
    }
    return a;
}

int main(){
    cout<<solve("aabebcdd")<<endl;
}