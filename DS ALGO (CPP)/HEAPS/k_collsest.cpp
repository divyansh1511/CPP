#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[] , int n , int k , int a){
    priority_queue<pair<int , int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({abs(arr[i] - a) , arr[i]});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        cout<<pq.top().second<<" ";
        pq.pop();
    }
}

int main(){
    int arr[] = {5,6,7,8,9};
    solve(arr , 5 , 3 , 7);
}