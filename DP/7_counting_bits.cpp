#include<bits/stdc++.h>
using namespace std;

vector<int> countingbits(int n){
    vector<int> dp(n+1 , 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i&(i-1)] + 1;
    }
    return dp;
}

int main(){

}