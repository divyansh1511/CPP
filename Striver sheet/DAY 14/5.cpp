#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> slidingwindow(vector<int> v , int k){
    int n = v.size();
    vector<int> ans;
    for (int i = 0; i < n-k+1; i++)
    {
        int maxi = INT_MIN;
        for (int j = i; j < i+k; j++)
        {
            maxi = max(maxi , v[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}

vector<int> slidingwindow1(vector<int> v , int k){
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        if (!dq.empty() && dq.front() == i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && v[dq.back()] < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k-1)
        {
            ans.push_back(v[dq.front()]);
        }
    }
    return ans;
}

int main(){
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = slidingwindow1(v , 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}