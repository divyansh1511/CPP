#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> anagrams(vector<string> v){
    unordered_map<string , vector<int>> mp;
    for (int i = 0; i < v.size(); i++)
    {
        string t = v[i];
        sort(t.begin() , t.end());
        mp[t].push_back(i);
    }
    vector<vector<int>> ans;
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){

}