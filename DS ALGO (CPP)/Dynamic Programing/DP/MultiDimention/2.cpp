#include<bits/stdc++.h>
using namespace std;

int longestarthe(vector<int> arr){
    int n = arr.size();
    int res = 0;
    vector<unordered_map<int,int>> dp(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = arr[i] - arr[j];
            dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
            res = max(res , dp[i][diff]);
        }
    }
    return res;
}

int main(){

}