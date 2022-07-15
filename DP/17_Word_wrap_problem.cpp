#include <bits/stdc++.h>
using namespace std;

int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> dp(n);
    int len = 0;
    int i = n - 1;
    for (i; i >= 0; i--)
    {
        len += nums[i];
        if (len > k)
        {
            break;
        }
        dp[i] = 0;
        len++;
    }
    for (i; i >= 0; i--)
    {
        int currlen = 0;
        long long mn = INT_MAX;
        for (int j = i; j < n - 1; j++)
        {
            currlen += nums[j];
            if (currlen > k)
            {
                break;
            }
            long long cost = (k - currlen) * (k - currlen) + dp[j + 1];
            mn = min(cost, mn);
            currlen++;
        }
        dp[i] = mn;
    }
    return dp[0];
}

int main()
{
}