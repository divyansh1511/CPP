#include<bits/stdc++.h>
using namespace std;

int subarrsum(vector<int> nums , int k){
    int sum = 0;
    int n = nums.size();
    map<int , int> mp;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            count++;
        }
        if (mp.find(sum - k) != mp.end())
        {
            count += mp[sum-k];
        }
        mp[sum]++;
    }
    return count;
}

int main(){

}