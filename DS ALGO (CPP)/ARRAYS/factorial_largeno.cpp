#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int arr[n+1];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = i*arr[i-1];
    }
    return arr[n];
}

int main(){
    cout<<factorial(10)<<endl;
}