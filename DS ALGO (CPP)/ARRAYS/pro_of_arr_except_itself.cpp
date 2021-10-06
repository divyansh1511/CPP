#include<iostream>
using namespace std;

void solve(int arr[] , int n){
    int ans[n];
    int pre = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = pre;
        pre *= arr[i];
    }
    int pos = 1;
    for (int i = n-1; i >= 0; i--)
    {
        ans[i] *= pos;
        pos *= arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main(){
    int arr[] = {1,2,3,4};
    solve(arr , 4);
}