#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int n){
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        if (i%2 == 0)
        {
            arr[i] = 4*arr[i/2];
        }
        else
        {
            arr[i] = 4*arr[i/2] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main(){
    solve(10);
}