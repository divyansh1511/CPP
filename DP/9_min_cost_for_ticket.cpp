#include<bits/stdc++.h>
using namespace std;

int mincost(vector<int> days , vector<int> cost){
    int dp[366] = {0};
    for (int i = 1; i < 366; i++)
    {
        auto it = find(days.begin() , days.end() , i);
        if (it == days.end())
        {
            dp[i] = dp[i-1];
        }
        else
        {
            dp[i] = min({dp[i-1]+cost[0] , dp[max(0 , i-7)]+cost[1] , dp[max(0 , i-30)]+cost[2]});
        }
    }
    return dp[365];
}

int main(){

}