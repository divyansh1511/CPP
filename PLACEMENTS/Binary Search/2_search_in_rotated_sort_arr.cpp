#include<bits/stdc++.h>
using namespace std;

int searchRotatedarr(int arr[] , int n , int k){
    int lo = 0 , hi = n-1;
    while (lo < hi)
    {
        int mid = (lo+hi)/2;
        if (arr[mid] > arr[hi])
        {
            lo = mid+1;
        }
        else
        {
            hi = mid;
        }
    }
    int rot = lo;
    lo = 0 , hi = n-1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        int realmid = (mid+rot)%n;
        if (arr[realmid] == k)
        {
            return realmid;
        }
        else if (arr[realmid] < k)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return -1;
}

int main(){

}