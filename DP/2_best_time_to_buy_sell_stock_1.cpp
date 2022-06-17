#include<bits/stdc++.h>
using namespace std;

int buyandsell(int arr[] , int n){
    int ans = 0;
    int minval = arr[0];
    for (int i = 1; i < n; i++)
    {
        minval = min(minval , arr[i]);
        ans = max(ans , arr[i]-minval);
    }
    return ans;
}

int main(){
    int arr[] = {7,1,5,3,6,4};
    cout<<buyandsell(arr , 6)<<endl;
}