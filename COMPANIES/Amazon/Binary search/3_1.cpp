#include<bits/stdc++.h>
using namespace std;

double median_of_arr(int arr1[] , int arr2[] , int n , int m){
    if (n > m)
    {
        return median_of_arr(arr2 , arr1 , m , n);
    }
    int lo = 0 , hi = n-1;
    int l1 , l2 , r1 , r2;
    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n+m)/2;
        l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
        l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
        r1 = cut1 == n ? INT_MAX : arr1[cut1];
        r2 = cut2 == m ? INT_MAX : arr2[cut2];
        if (l1 > r2)
        {
            hi = cut1 - 1;
        }
        else if (l2 > r1)
        {
            lo = cut1+1;
        }
        else
        {
            return (n+m)%2 == 0 ? (max(l1 , l2) + min(r1 , r2))/2.0 : (double)min(r1 , r2);
        }
    }
}

int main(){

}