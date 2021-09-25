#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countpairs(vector<int> arr , int k){
    unordered_map<int , int> mp;
    int res = 0;
    for (auto num : arr)
    {
        res += mp[num + k] + mp[num - k];
        mp[num]++;
    }
    return res;
}

int main(){
    vector<int> arr = {1,2,2,1};
    cout<<countpairs(arr , 1)<<endl;
}