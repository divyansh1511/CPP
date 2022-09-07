#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
    // vector<int> ans , odd;
    // for(int i=0;i<nums.size();i++){
    //     if(nums[i] % 2 == 0){
    //         ans.push_back(nums[i]);
    //     }
    //     else{
    //         odd.push_back(nums[i]);
    //     }
    // }
    // for(int i=0;i<odd.size();i++){
    //     ans.push_back(odd[i]);
    // }
    // return ans;
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
        {
            if (nums[j] % 2 == 0)
            {
                j = i + 1;
                continue;
            }
            if (i != j)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
    return nums;
}

int main()
{
    
}