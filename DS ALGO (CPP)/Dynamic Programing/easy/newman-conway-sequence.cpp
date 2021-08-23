#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int n){
    int arr[n+1];
    memset(arr , -1 , n);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[arr[i-1]] + arr[i-arr[i-1]];
    }
    
    for (int i = 0; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}

int main(){
    solve(13);
}