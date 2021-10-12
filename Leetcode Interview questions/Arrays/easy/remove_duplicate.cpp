#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//-------------BRUTE FORCE---------------//-----------O(N^2)-------------//

int removeDuplicates(vector<int>& nums){
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
    }
    return n - count;
}

//---------------OPTIMISED APPROCH--------//----------O(N)----------//

int removeDuplicates1(vector<int>& nums){
    set<int> s(nums.begin() , nums.end());
    nums.assign(s.begin() , s.end());
    return s.size();
}

int main(){
    vector<int> nums = {1,1,2};
    cout<<removeDuplicates1(nums)<<endl;    
}