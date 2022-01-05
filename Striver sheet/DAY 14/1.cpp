#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nearestsmaller(vector<int> v){
    int n = v.size();
    vector<int> ans;
    ans.push_back(-1);
    for (int i = 1; i < n; i++)
    {
        int j;
        for (j = i-1; j >= 0; j--)
        {
            if (v[j] < v[i])
            {
                ans.push_back(v[j]);
                break;
            }
        }
        if (j == -1)
        {
            ans.push_back(-1);   
        }
    }
    return ans;
}

vector<int> nearestsmalleropti(vector<int> v){
    stack<int> s;
    vector<int> a;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() >= v[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            a.push_back(-1);
        }
        else
        {
            a.push_back(s.top());
        }
        s.push(v[i]);
    }
    return a;
}

int main(){
    vector<int> v = {4, 5, 2, 10, 8};
    vector<int> ans = nearestsmalleropti(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}