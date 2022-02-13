#include<bits/stdc++.h>
using namespace std;

int median(int arr1[] , int arr2[] , int n , int m){
    int lo = 0 , hi = n;
    int l1 , l2 , r1 , r2;
    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n+m)/2 - cut1;
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
            lo = cut1 + 1;
        }
        else
        {
            return (n+m)%2 == 0 ? (max(l1 , l2) + min(r1 , r2))/2 : min(r1 , r2);
        }
    }
}

int main(){
    int arr1[] = { -48, -31, -15, -6, 1, 8 };
    int arr2[] = {-40, -25, 5, 10, 14, 28, 29, 48 };
    cout<<median(arr1 , arr2 , 6 , 8)<<endl;
}