#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr[] , int n){
    int currsum = 0 , totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i]*i;
        totalsum += arr[i];
    }
    int ans = currsum;
    for (int i = 1; i < n; i++)
    {
        int temp = currsum - (totalsum - arr[i-1]) + arr[i-1]*(n-1);
        ans = max(ans , temp);
        currsum = temp;
    }
    return ans;
}

int main(){

}