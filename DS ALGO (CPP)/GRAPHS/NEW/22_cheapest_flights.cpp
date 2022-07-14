#include<bits/stdc++.h>
using namespace std;

int findCheapestFlights(vector<vector<int>> flights , int n , int src , int dst , int k){
    vector<vector<int>> dp(k+2 , vector<int>(n , INT_MAX));

    for (int i = 0; i <= k+1; i++)
    {
        dp[i][src] = 0;
    }
    for (int i = 1; i <= k+1; i++)
    {
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (dp[i-1][u] != INT_MAX)
            {
                dp[i][v] = min(dp[i][v] , dp[i-1][u]+w);
            }
        }
    }
    return dp[k+1][dst] == INT_MAX ? -1 : dp[k+1][dst];
}

int main(){

}