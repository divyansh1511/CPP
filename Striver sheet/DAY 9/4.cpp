#include<bits/stdc++.h>
using namespace std;

void helper(int index , int target , vector<int> v , vector<vector<int>> &ans , vector<int> &ds){
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (i > index && v[i] == v[i-1])
        {
            continue;
        }
        if (v[i] > target)
        {
            break;
        }
        ds.push_back(v[i]);
        helper(i+1 , target - v[i] , v , ans , ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationsum2(vector<int> v , int target){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    vector<int> ds;
    helper(0 , target , v , ans , ds);
    return ans;
}

int main(){
    
}