#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//-------------BRUTE FORCE------------------//-----------O(N^2)--------------//
vector<int> twoSum(vector<int> v , int target){
    vector<int> a;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (v[i] + v[j] == target)
            {
                a.push_back(i);
                a.push_back(j);
                return a;
            }
        }
    }
    a.push_back(-1);
    return a;
}

//----------------SECOND APPROCH----------------//-------O(NlogN)----------//
vector<int> twoSum2(vector<int> v , int target){
    vector<int> ans;
    sort(v.begin() , v.end());
    int n = v.size();
    int st = 0 , en = n-1;
    while (st < en)
    {
        if (v[st] + v[en] == target)
        {
            ans.push_back(st);
            ans.push_back(en);
            return ans;
        }
        else if (v[st] + v[en] < target)
        {
            st++;
        }
        else
        {
            en--;
        }
    }
    ans.push_back(-1);
    return ans;
}

//------------------OPTIMISE APPROCH----------------//---------O(N)--------//
vector<int> twoSum3(vector<int> v , int target){
    unordered_map<int , int> mp;
    int n = v.size();
    for (int i = 0; i < v.size(); i++)
    {
        if (mp.find(target - v[i]) != mp.end())
        {
            return {mp[target - v[i]] , i};
        }
        mp[v[i]] = i;
    }
    return {};
}

int main(){
    vector<int> s = {2,7,11,15};
    vector<int> a = twoSum3(s , 9);
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    
}