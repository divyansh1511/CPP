#include<bits/stdc++.h>
using namespace std;

int longestcons(int arr[] , int n){
    if (n == 0)
    {
        return 0;
    }
    int ans = 0;
    int count = 1;
    sort(arr , arr+n);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i-1])
        {
            continue;
        }
        if (arr[i] != arr[i-1]+1)
        {
            ans = max(ans , count);
            count = 1;
        }
        else
        {
            count++;
        }
    }
    return ans;
}

int main(){

}