#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums){
    int j = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }
    for(;j<nums.size();j++){
        nums[j] = 0;
    }
}

int main(){
    vector<int> nums = {0,2,3,0,5,0,1};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
}