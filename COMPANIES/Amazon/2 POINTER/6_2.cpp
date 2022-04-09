#include<bits/stdc++.h>
using namespace std;

int threesum(int arr[] , int n , int k){
    sort(arr , arr+n);
    int mini = INT_MAX;
    int res = 0;
    for (int i = 0; i <= n-2; i++)
    {
        int lo = i+1 , hi = n;
        while (lo < hi)
        {
            res = arr[i] + arr[lo] + arr[hi];
            if (res == k)
            {
                return res;
            }
            if (abs(res - k) < abs(k - mini))
            {
                mini = res;
            }
            else if (res > k)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
    }
    return mini;
}

int main(){

}