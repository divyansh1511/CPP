#include<bits/stdc++.h>
using namespace std;

void counter(vector<int> &nums , int st , int mid , int end , int &count){
    int l = st , r = mid+1;
    while (l <= mid && r <= end)
    {
        if((long)nums[l] > (long)nums[r]*2){
            count += (mid-l+1);
            r++;
        }
        else
        {
            l++;
        }
    }
    sort(nums.begin()+st , nums.begin()+end+1);
}

void mergesort(vector<int> &nums , int st , int end , int &count){
    if (st == end)
    {
        return;
    }
    int mid = (st + end)/2;
    mergesort(nums , st , mid , count);
    mergesort(nums , mid+1 , end , count);
    counter(nums , st , mid , end , count); 
}

int reversePairs(vector<int> &nums){
    if (nums.size() == 0)
    {
        return 0;
    }
    int count = 0;
    mergesort(nums , 0 , nums.size()-1 , count);
    return count;
}

int main(){

}