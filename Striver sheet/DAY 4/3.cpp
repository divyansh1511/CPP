//--------------------LONGEST CONSICUTIVE SEQUENCE----------------------//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestsuquence(vector<int> nums)
{
    int n = nums.size();
    int ans = 0;
    int sum = 1;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            continue;
        }
        if (nums[i] != nums[i - 1] + 1)
        {
            ans = max(ans, sum);
            sum = 1;
        }
        else
        {
            sum++;
        }
    }
    return max(ans, sum);
}

int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestsuquence(nums) << endl;
}