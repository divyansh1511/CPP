#include<bits/stdc++.h>
using namespace std;

void helper(int index , int target , vector<int> v , vector<vector<int>> &ans , vector<int> ds){
    if (index == v.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (v[index] <= target)
    {
        ds.push_back(v[index]);
        helper(index , target-v[index] , v , ans , ds);
        ds.pop_back();
    }
    helper(index+1 , target , v , ans , ds);
}

vector<vector<int>> combinationsum(vector<int> v , int target){
    vector<vector<int>> ans;
    vector<int> ds;
    helper(0 , target , v , ans , ds);
    return ans;
}

int main(){
    vector<int> v = {2,3,6,7};
    vector<vector<int>> ans = combinationsum(v , 7);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}