#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[][2] , int n , int k){
    priority_queue<pair<int , pair<int , int>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({arr[i][0]*arr[i][0] + arr[i][1] * arr[i][1] , {arr[i][0] , arr[i][1]}});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        cout<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
        pq.pop();
    }
}

int main(){
    int arr[4][2] = {{1,3},{-2,2},{5,8},{0,1}};
    solve(arr , 4 , 1);
}