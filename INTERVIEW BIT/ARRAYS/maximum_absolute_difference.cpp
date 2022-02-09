#include<bits/stdc++.h>
using namespace std;

int maxabsdiff(int arr[] , int n){
    int max1 = arr[0];
    int max2 = arr[0];
    int min1 = arr[0];
    int min2 = arr[0];
    for (int i = 1; i < n; i++)
    {
        max1 = max(max1 , arr[i]+i);
        max2 = max(max2 , arr[i]-i);
        min1 = min(min1 , arr[i]+i);
        min2 = min(min1 , arr[i]-i);
    }
    int ans;
    ans = max((max1-min1) , (max2 - min2));
    return ans;
}

int main(){

}