//------------BEST TIME TO BUY STOCKS----------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxprofit(int arr[] , int n){
    int mininum = INT_MAX;
    int maxnum = 0;
    for (int i = 0; i < n; i++)
    {
        mininum = min(mininum , arr[i]);
        maxnum = max(maxnum , arr[i] - mininum);
    }
    return maxnum;
}

int main(){
    int arr[] = {7,1,5,3,6,4};
    cout<<maxprofit(arr , 6)<<endl;
}