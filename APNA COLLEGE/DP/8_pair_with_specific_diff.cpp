#include<bits/stdc++.h>
using namespace std;

int pair_specific(int arr[] , int n , int k){
    sort(arr , arr+n);
    int maxsum = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (arr[i] - arr[i-1] < k)
        {
            maxsum += arr[i];
            maxsum -= arr[i-1];
            i--;
        }
    }
    return maxsum;
}

int main(){

}