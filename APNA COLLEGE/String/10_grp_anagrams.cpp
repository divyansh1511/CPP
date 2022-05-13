#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> grp_anagrams(vector<string> &v){
    unordered_map<string , vector<string>> mp;
    for (int i = 0; i < v.size(); i++)
    {
        string s = v[i];
        sort(s.begin() , s.end());
        mp[s].push_back(v[i]);
    }
    vector<vector<string>> ans;
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){

}