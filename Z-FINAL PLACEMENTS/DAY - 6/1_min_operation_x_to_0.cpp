#include<bits/stdc++.h>
using namespace std;

int minoperation(vector<int> &nums , int x){
    int n = nums.size();
    int sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += nums[i];
    }
    if (x > sum1)
    {
        return -1;
    }
    int sum = 0;
    int ans = -1;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        while (sum > sum1 - x && i >= j)
        {
            sum -= nums[j++];
        }
        if (sum == sum1 - x)
        {
            ans = max(ans , i-j+1);
        }
    }
    return ans;
}

int main(){

}