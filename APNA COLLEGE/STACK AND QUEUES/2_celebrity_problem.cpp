#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (M[left][right] == 1)
            left++;
        else
            right--;
    }

    int potentialCandidate = left;

    for (int i = 0; i < n; i++)
    {
        if (i != potentialCandidate)
        {
            if (M[potentialCandidate][i] == 1 || M[i][potentialCandidate] == 0)
                return -1;
        }
    }

    return potentialCandidate;
}

int main()
{
}