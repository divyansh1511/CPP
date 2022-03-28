#include<bits/stdc++.h>
using namespace std;

int climbing_stairs(vector<int> cost){
    int n = cost.size();
    vector<int> dp(n+1 , 0);
    for (int i = 2; i <= n; i++)
    {
        int one = dp[i-1] + cost[i-1];
        int two = dp[i-2] + cost[i-2];
        dp[i] = min(one , two);
        // cout<<dp[i]<<endl;
    }
    return dp[n];
}

int main(){
    vector<int> cost = {10,15,20};
    cout<<climbing_stairs(cost)<<endl;
}