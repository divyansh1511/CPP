#include<iostream>
using namespace std;

int xorOperations(int n , int start){
    int arr[n];
    int xor_arr = 0;
    for (int i=0;i<n;i++){
        arr[i] = start+ 2*i;
    }
    for (int i = 0; i < n; i++)
    {
        xor_arr = xor_arr ^ arr[i];
    }
    return xor_arr;
}

int main(){
    int n,start;
    cin>>n>>start;
    cout<<xorOperations(n , start);
}

// Given an integer n and an integer start.

// Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.

// Return the bitwise XOR of all elements of nums.