#include<bits/stdc++.h>
using namespace std;

int maximum_absolute_diff(int arr[] , int n){
    int max1 = arr[0];
    int max2 = arr[0];
    int min1 = arr[0];
    int min2 = arr[0];
    for (int i = 0; i < n; i++)
    {
        max1 = max(max1 , arr[0]+i);
        max2 = max(max2 , arr[0]-i);
        min1 = min(min1 , arr[0]+i);
        min2 = min(min2 , arr[0]-i);
    }
    int ans = max(max1-min1 , max2 - min2);
    return ans;
}

int main(){
    
}