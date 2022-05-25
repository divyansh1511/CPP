#include<bits/stdc++.h>
using namespace std;

int permutation(int n , int k){
    int dp[n+1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = i*dp[i-1];
    }
    return dp[n]/dp[n-k];
}

int main(){

}