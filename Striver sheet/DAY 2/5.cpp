//------------------repeat and missing number--------------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> missingandrepeat(vector<int> v){
    sort(v.begin() , v.end());
    vector<int> ans;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == v[i+1])
        {
            ans.push_back(v[i]);
        }
        else if (v[i+1] != v[i]+1)
        {
            ans.push_back(v[i]+1);
        }
    }
    return ans;
}

int main(){
    vector<int> v = {3,1,2,5,3};
    vector<int> ans = missingandrepeat(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}