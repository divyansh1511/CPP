#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[] , int n , int k){
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
    unordered_map<int , int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        pq.push({it->second , it->first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout<<pq.top().second<<" ";
        pq.pop();
    }
}

int main(){
    int arr[] = {1,1,1,3,2,2,4};
    solve(arr , 7 , 2);
}