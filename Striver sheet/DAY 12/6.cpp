#include<bits/stdc++.h>
using namespace std;

int kthlargest(int arr[] , int n , int k){
    unordered_map<int , int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    for (auto it : mp)
    {
        pq.push({it.second , it.first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top().second;
}

int main(){

}