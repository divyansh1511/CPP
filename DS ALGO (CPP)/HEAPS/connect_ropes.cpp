#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[] , int n){
    priority_queue<int , vector<int> , greater<int>> pq;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() >= 2)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        sum = sum+first+second;
        pq.push(first+second);
    }
    cout<<sum<<endl;
} 

int main(){
    int arr[] = {1,2,3,4,5};
    solve(arr , 5);
}