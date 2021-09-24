#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> nums , int k){
    unordered_map<int , int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k)
        {
            return true;
        }
        mp[nums[i]]++;
    }
    return false;
}

int main(){
    vector<int> nums = {1,2,3,1};
    cout<<solve(nums , 3)<<endl;
}