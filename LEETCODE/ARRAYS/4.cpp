#include<bits/stdc++.h>
using namespace std;

double median(int arr1[] , int arr2[] , int n , int m){
    int lo = 0 , hi = n;
    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n+m)/2 - cut1;
        int l1 = (cut1 == 0) ? INT16_MIN : arr1[cut1-1];
        int l2 = (cut2 == 0) ? INT16_MIN : arr2[cut2-1];
        int r1 = (cut1 == n) ? INT16_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT16_MAX : arr2[cut2];

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
            return (n+m)%2 == 0 ? (max(l1 , l2) + min(r1 , r2))/2.0 : min(r1 , r2); 
        }
    }
    return -1.0;
}

int main(){
    int arr1[] = {1};
    int arr2[] = {0};
    cout<<median(arr1 , arr2 , 1, 0)<<endl;

}