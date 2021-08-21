#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int prime(int n){
    if (n==0 || n==1)
    {
        return 1;
    }
    return 2*prime(n-1)+prime(n-2);
}

int primedp(int n){
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 2*dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    cout<<prime(3)<<endl;
    cout<<primedp(3)<<endl;
}