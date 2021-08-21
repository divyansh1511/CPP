#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cutrod(int prices[] , int n){
    int val[n+1];
    val[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            max_val = max(max_val , prices[j]+val[i-j-1]);
        }
        val[i] = max_val;
    }
    return val[n];
}

int main(){
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<cutrod(arr , size)<<endl;
}