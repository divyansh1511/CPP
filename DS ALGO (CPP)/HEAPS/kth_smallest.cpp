#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] , int n , int k){
    priority_queue<int> maxheap;
    for (int i = 0; i < n; i++)
    {
        maxheap.push(arr[i]);
        if (maxheap.size() > k)
        {
            maxheap.pop();
        }
    }
    return maxheap.top();
}

int main(){
    int arr[] = {5,7,2,3,9};
    cout<<solve(arr , 5,3)<<endl;
}