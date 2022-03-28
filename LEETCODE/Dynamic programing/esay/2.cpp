#include<bits/stdc++.h>
using namespace std;

int fibnoccinum(int n){
    if (n <= 2)
    {
        return 1;
    }
    return fibnoccinum(n-1) + fibnoccinum(n-2);
}

int fibnoccinumdp(int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    cout<<fibnoccinum(3)<<endl;
    cout<<fibnoccinum(3)<<endl;
}