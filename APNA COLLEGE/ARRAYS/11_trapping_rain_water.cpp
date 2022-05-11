#include<bits/stdc++.h>
using namespace std;

int trapping_rain_water(int arr[] , int n){
    int left[n] , right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1] , arr[i]);
    }
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1] , arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(left[i] , right[i]) - arr[i];
    }
    return sum;
}

//--------------------second method----------------//

int trapping_rain(int arr[] , int n){
    int l = 0 , r = n-1;
    int ml = 0 , mr = 0;
    int ans = 0;
    while (l <= r)
    {
        if (arr[l] < arr[r])
        {
            if (arr[l] > ml)
            {
                ml = arr[l];
            }
            else
            {
                ans += ml - arr[l];
            }
            l++;
        }
        else
        {
            if (arr[r] > mr)
            {
                mr = arr[r];
            }
            else
            {
                ans += mr - arr[r];
            }
            r--;
        }
    }
    return ans;
}

int main(){
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trapping_rain_water(arr , 12)<<endl;
}