#include<bits/stdc++.h>
using namespace std;

int longestArthematicProgression(int A[] , int n){
    if (n <= 2)
    {
        return n;
    }
    int mxlen = 2;
    vector<unordered_map<int,int>> dp(n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int diff = A[j] - A[i];
            if (dp[i].find(diff) != dp[i].end())
            {
                dp[j][diff] = dp[i][diff]+1;
            }
            else
            {
                dp[j][diff] = 2;
            }
            mxlen = max(mxlen , dp[j][diff]);
        }
    }
    return mxlen;
}

int main(){

}