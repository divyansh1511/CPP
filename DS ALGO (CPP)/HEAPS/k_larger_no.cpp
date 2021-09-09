#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[] , int n , int k){
    priority_queue<int , vector<int> , greater<int>> minheap;
    for (int i = 0; i < n; i++)
    {
        minheap.push(arr[i]);
        if (minheap.size() > k)
        {
            minheap.pop();
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout<<minheap.top()<<endl;
        minheap.pop();
    }
}

int main(){
    int arr[] = {5,6,2,3,4};
    solve(arr , 5 , 3);
}