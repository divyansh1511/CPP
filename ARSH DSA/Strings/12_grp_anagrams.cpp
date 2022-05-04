#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> grpanagrams(vector<string> v){
    unordered_map<string , vector<string>> mp;
    for(auto it : v){
        string t = it;
        sort(t.begin() , t.end());
        mp[t].push_back(it);
    }
    vector<vector<string>> ans;
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){

}