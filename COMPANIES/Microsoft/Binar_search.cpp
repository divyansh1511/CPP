#include<bits/stdc++.h>
using namespace std;

//------------------------------------------------------------------------------------

int median_of_arr(vector<int> arr1 , vector<int> arr2){
    int n = arr1.size() , m = arr2.size();
    if (n > m)
    {
        return median_of_arr(arr2 , arr1);
    }
    int lo = 0 , hi = n;
    int l1 , l2 , r1 , r2;
    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n+m)/2 - cut1;
        l1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
        l2 = (cut2 == 0) ? INT_MIN : arr2[cut2-1];
        r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        r2 = (cut2 == m) ? INT_MAX : arr2[cut2];
        if (l1 > r2)
        {
            hi = cut1-1;
        }
        else if (l2 > r1)
        {
            lo = cut1+1;
        }
        else
        {
            return (n+m)%2 == 0 ? (max(l1 , l2) , min(r1 , r2))/2.0 : (double)min(r1 , r2);
        }
    }
}

//------------------------------------------------------------------------------

int firstposition(int arr[] , int n , int k){
    int lo = 0 , hi = n-1;
    int mid = lo + (hi-lo)/2;
    int ans = -1;
    while (lo <= hi)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            hi = mid-1;
        }
        else if (arr[mid] < k)
        {
            lo = mid+1;
        }
        else if (arr[mid] > k)
        {
            hi = mid-1;
        }
        mid = (lo+hi)/2;
    }
    return ans;
}

int lastposition(int arr[] , int n , int k){
    int lo = 0 , hi = n-1;
    int mid = lo + (hi-lo)/2;
    int ans = -1;
    while (lo <= hi)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            lo = mid+1;
        }
        else if (arr[mid] < k)
        {
            lo = mid+1;
        }
        else if (arr[mid] > k)
        {
            hi = mid-1;
        }
        mid = (lo+hi)/2;
    }
    return ans;
}

vector<int> searchrange(int arr[] , int n , int k){
    vector<int> v;
    int a = firstposition(arr , n , k);
    if (a == -1)
    {
        return {-1 , -1};
    }
    v.push_back(a);
    int b = lastposition(arr , n , k);
    v.push_back(b);
    return v;
}

//-----------------------------------------------------------------

int square_root_int(int n){
    int i = 0 , j = n;
    int mid = (i+j)/2;
    int ans = -1;
    while (i <= j)
    {
        long int sq = mid*mid;
        if (sq == n)
        {
            return sq;
        }
        if (sq > n)
        {
            j = mid - 1;
        }
        else
        {
            ans = mid;
            i = mid+1;
        }
        mid = (i+j)/2;
    }
    return ans;
}

int main(){

}