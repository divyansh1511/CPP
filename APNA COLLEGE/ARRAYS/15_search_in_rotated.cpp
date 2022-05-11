#include<bits/stdc++.h>
using namespace std;

int searchinrotated(int arr[] , int n , int key){
    int l = 0 , r = n-1;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (arr[mid] > arr[r])
        {
            l = mid+1;
        }
        else
        {
            r = mid;
        }
    }
    int rot = l;
    l = 0;
    r = n-1;
    while (l <= r)
    {
        int mid = (l+r)/2;
        int realmid = (rot+mid)%n;
        if (arr[realmid] == key)
        {
            return realmid;
        }
        if (arr[realmid] < key)
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    return -1;
}

int main(){

}