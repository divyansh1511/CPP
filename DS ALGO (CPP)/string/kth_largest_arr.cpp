#include<iostream>
#include<bits/stdc++.h>
using namespace std;

static bool cmp(string s1 , string s2){
    if (s1.length() < s2.length())
    {
        return true;
    }
    else if (s2.length() < s1.length())
    {
        return false;
    }
    else
    {
        return s1 < s2;
    }
}

string solve(vector<string> nums , int k){
    sort(nums.begin() , nums.end() , cmp);
    return nums[nums.size() - k];
}

int main(){
    vector<string> nums = {"3","6","7","10"};
    cout<<solve(nums , 4)<<endl;
}