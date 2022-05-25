#include<bits/stdc++.h>
using namespace std;

int countBBT(int h){
    int dp[h+1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i < h; i++)
    {
        dp[i] = (dp[i-1] * (2*dp[i-2] + dp[i-1]));
    }
    return dp[h];
}

int main(){

}