#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string , vector<string>> mp;
    for (auto s : strs)
    {
        string t = s;
        sort(t.begin() , t.end());
        mp[t].push_back(s);
    }
    vector<vector<string>> v;
    for (auto it : mp)
    {
        v.push_back(it.second);
    }
    return v;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}