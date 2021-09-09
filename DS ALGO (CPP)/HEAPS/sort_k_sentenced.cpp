#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[] , int n , int k){
    priority_queue<int , vector<int> , greater<int>> minheap;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        minheap.push(arr[i]);
        if (minheap.size() > k)
        {
            v.push_back(minheap.top());
            minheap.pop();
        }
    }
    while (!minheap.empty())
    {
        v.push_back(minheap.top());
        minheap.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
}

int main(){
    int arr[] = {6,5,3,2,8,10,9};
    solve(arr , 7 , 3);
}