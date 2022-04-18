#include<bits/stdc++.h>
using namespace std;

double mediansortedarr(vector<int> arr1 , vector<int> arr2){
    int n = arr1.size();
    int m = arr2.size();
    if (n > m)
    {
        return mediansortedarr(arr2 , arr1);
    }
    int lo = 0 , hi = n;
    while (lo <= hi)
    {
        int cut1 = lo + (hi-lo)/2;
        int cut2 = (n+m+1)/2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2-1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];
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

int main(){

}