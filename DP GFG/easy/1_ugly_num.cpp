#include<bits/stdc++.h>
using namespace std;

int uglynum(int n){
    int c2 = 0 , c3 = 0 , c5 = 0;
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = min({2*dp[c2] , 3*dp[c3] , 5*dp[c5]});
        if (2*dp[c2] == dp[i])
        {
            c2++;
        }
        if (3*dp[c3] == dp[i])
        {
            c3++;
        }
        if (5*dp[c5] == dp[i])
        {
            c5++;
        }
    }
    return dp[n-1];
}

int main(){
    cout<<uglynum(5)<<endl;
}