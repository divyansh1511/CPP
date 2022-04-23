#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v(n);
    int i = 0, j = n - 1, k = n - 1;
    while (i <= j)
    {
        if (abs(nums[i]) > abs(nums[j]))
        {
            v[k] = nums[i] * nums[i];
            i++;
            k--;
        }
        else
        {
            v[k] = nums[j] * nums[j];
            j--;
            k--;
        }
    }
    return v;
}

int main()
{
    
}