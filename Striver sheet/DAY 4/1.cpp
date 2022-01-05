//------------------------TWO SUM--------------------------------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int> num , int target){
    unordered_map<int , int> mp;
    for (int i = 0; i < num.size(); i++)
    {
        if (mp.find(target - num[i]) != mp.end())
        {
            return {mp[target-num[i]] , i};
        }
        mp[num[i]] = i;
    }
    return {};
}

int main(){
    vector<int> num = {3,2,4};
    vector<int> v = twosum(num , 6);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}