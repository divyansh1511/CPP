#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] , int n , int k){
    sort(arr, arr + n);
    int i=0;
    int sum = 0;
    while (k > 0)
    {
        if (arr[i] >= 0)
        {
            k = 0;
        }
        else
        {
            arr[i] = arr[i]*(-1);
            k--;
        }
        i++;
    }
    for(int j = 0; j < n; j++)
    {
        sum += arr[j];
    }
    return sum;
}

int main(){
    
}