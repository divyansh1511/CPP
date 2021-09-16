// Given an array of integers nums.

// A pair (i,j) is called good if nums[i] == nums[j] and i < j.

// Return the number of good pairs.

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    int count = 0;
    for(int i=0 ; i<nums.size();i++){
        for(int j=i+1 ; j<nums.size();j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }
    }
    return count;
}

void solve(vector<int>& nums){
    int count = 0;
    unordered_map<int , int> mp;
    for (int i : nums)
    {
        count += mp[i]++;
    }
    cout<<count<<endl;
}

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<numIdenticalPairs(arr)<<endl;
    solve(arr);
}