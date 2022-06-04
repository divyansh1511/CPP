#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> nums , vector<vector<int>> &ans , int si){
    if (si >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = si; i < nums.size(); i++)
    {
        swap(nums[si] , nums[i]);
        helper(nums , ans , si+1);
        swap(nums[si] , nums[i]);
    }
}

vector<vector<int>> permute(vector<int> nums){
    vector<vector<int>> ans;
    helper(nums , ans , 0);
    return ans;
}

int main(){

}