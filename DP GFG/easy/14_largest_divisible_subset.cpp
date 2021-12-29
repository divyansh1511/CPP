#include<bits/stdc++.h>
using namespace std;

int largestsubset(int arr[] , int n){
    int dp[n];
    dp[n-1] = 1;
    for (int i = n-2; i >= 0; i--)
    {
        int mxm = 0;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]%arr[i] == 0 || arr[i]%arr[j] == 0)
            {
                mxm = max(mxm , dp[j]);
            }
        }
        dp[i] = 1+mxm;
    }
    int a = dp[0];
    for (int i = 1; i < n; i++)
    {
        a = max(a , dp[i]);
    }
    return a;
}

int main(){
    int a[] = { 1, 3, 6, 13, 17, 18 };
    int n = sizeof(a) / sizeof(a[0]);
    cout<<largestsubset(a, n)<<endl;
    return 0;
}