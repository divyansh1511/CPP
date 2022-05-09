#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> anagrams(vector<string> v){
    unordered_map<string , vector<string>> mp;
    for (int i = 0; i < v.size(); i++)
    {
        string t = v[i];
        sort(t.begin() , t.end());
        mp[t].push_back(v[i]);
    }
    vector<vector<string>> ans;
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){

}