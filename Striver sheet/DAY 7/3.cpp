#include <iostream>
using namespace std;

int solve(int arr[], int n)
{
    int left[n];
    int right[n];
    int sum = 0;
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(arr[i], left[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(arr[i], right[i + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += (min(left[i], right[i]) - arr[i]);
    }
    return sum;
}

int solveopti(int height[], int n)
{
    int low = 0;
    int high = n - 1;
    int ml = 0;
    int mr = 0;
    int ans = 0;
    while (low <= high)
    {
        if (height[low] < height[high])
        {
            if (height[low] > ml)
            {
                ml = height[low];
            }
            else
            {
                ans = ans + ml - height[low];
            }
            low++;
        }
        else
        {
            if (height[high] > mr)
            {
                mr = height[high];
            }
            else
            {
                ans = ans + mr - height[high];
            }
            high--;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << solve(arr, 12) << endl;
    cout << solveopti(arr, 12) << endl;
}