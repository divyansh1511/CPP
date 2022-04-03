#include<bits/stdc++.h>
using namespace std;

int lenlongestsubsequence(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n , vector<int>(1000 , 1));
    unordered_map<int , int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i-1; j >= 0; j--)
        {
            res = max(res , dp[j][i]+1);
            int need = arr[j]+arr[i];
            if (mp.find(need) != mp.end())
            {
                dp[i][mp[need]] = dp[j][i] + 1;
            }
        }
    }
    return res > 2 ? res : 0;
}

int main(){

}