#include <bits/stdc++.h>
using namespace std;

int maxSubstring(string S)
{
    // Your code goes here
    int sum = 0, maxi = -1;
    for (int i = 0; i < S.length(); i++)
    {
        if (sum < 0)
        {
            sum = 0;
        }
        if (S[i] == '0')
        {
            sum++;
        }
        else
        {
            sum--;
        }
        maxi = max(maxi, sum);
    }
    return maxi;
}

int main()
{
}