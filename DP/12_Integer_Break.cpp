#include<bits/stdc++.h>
using namespace std;

// 394373

int integerbreak(int n){
    if (n <= 2)
    {
        return 1;
    }
    vector<int> dp(n+1 , 0);
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = max({dp[i] , j*(i-j) , j*dp[i-j]});
        }
    }
    return dp[n];
}

int main(){

}