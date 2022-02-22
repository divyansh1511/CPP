#include<bits/stdc++.h>
using namespace std;

vector<int> givenindex(vector<int> v , int target){
    int n = v.size();
    vector<int> ans;
    unordered_map<int , int> mp;
    for (int i = 0; i < n; i++)
    {
        int res = target - v[i];
        if (mp.find(res) != mp.end())
        {
            ans.push_back(mp[res]);
            ans.push_back(i+1);
            break;
        }
        if (mp.find(v[i]) == mp.end())
        {
            mp[v[i]] = i+1;
        }
    }
    return ans;
}

int main(){
    vector<int> v = {2,7,11,15};
    vector<int> ans = givenindex(v , 9);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}