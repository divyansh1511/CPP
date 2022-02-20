#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &ans , vector<int> nums , int index){
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i] , nums[index]);
        helper(ans , nums , index+1);
        swap(nums[i] , nums[index]);
    }
}

vector<vector<int>> permute(vector<int> nums){
    vector<vector<int>> ans;
    int index = 0;
    helper(ans , nums , index);
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> v = permute(nums);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}