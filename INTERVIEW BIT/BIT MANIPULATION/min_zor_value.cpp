#include<bits/stdc++.h>
using namespace std;

int min_val(int arr[] , int n){
    int ans = INT_MAX;
    sort(arr , arr+n);
    for (int i = 0; i < n-1; i++)
    {
        ans = min(ans , arr[i]^arr[i+1]);
    }
    return ans;
}

int main(){
    int arr[] = {0 , 2 , 5 , 7};
    cout<<min_val(arr , 4)<<endl;
}