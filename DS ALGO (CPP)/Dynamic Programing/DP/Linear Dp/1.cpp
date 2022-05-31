#include<bits/stdc++.h>
using namespace std;

//-----------recursion--------------//

int climbingstairs(int n){
    if (n <= 2)
    {
        return n;
    }
    return climbingstairs(n-1) + climbingstairs(n-2);
}

//------------Dp-------------------//

int climbingstairsDP(int n){
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    cout<<climbingstairs(3)<<endl;
    cout<<climbingstairsDP(3)<<endl;
}