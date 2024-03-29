#include<bits/stdc++.h>
using namespace std;

double helper(vector<int> nums1 , vector<int> nums2){
    int n = nums1.size() , m = nums2.size();
    if(n > m){
        return helper(nums2 , nums1);
    }
    int lo = 0 , hi = n;
    while (lo <= hi)
    {
        int cut1 = lo + (hi-lo)/2;
        int cut2 = (n+m+1)/2 - cut1;

        int l1 = cut1 == 0 ? INT_MAX : nums1[cut1-1];
        int l2 = cut2 == 0 ? INT_MAX : nums2[cut2-1];
        int r1 = cut1 == n ? INT_MIN : nums1[cut1];
        int r2 = cut2 == n ? INT_MIN : nums2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n+m)%2 == 0)
            {
                return (double)(max(l1 , l2) + min(r1 , r2))/2;
            }
            else
            {
                return (double)(max(l1 , l2));
            }
        }
        else if (l1 > r2)
        {
            hi = cut1 - 1;
        }
        else
        {
            lo = cut1 + 1;
        }
    }
    return -1.0;
}

double mediansortedarr(vector<int> nums1 , vector<int> nums2){
    double ans;
    ans = helper(nums1 , nums2);
    return ans;
}

int main(){

}