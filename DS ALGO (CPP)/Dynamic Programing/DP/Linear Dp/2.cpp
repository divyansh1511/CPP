#include<bits/stdc++.h>
using namespace std;

int besttimeI(int arr[] , int n){
    int left[n] , right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = min(left[i-1] , arr[i]); 
    }
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1] , arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(sum , right[i] - left[i]);
    }
    return sum;
}

///------------opti---------------///

int besttime(int arr[] , int n){
    int minele = INT_MAX;
    int maxele = 0;
    for (int i = 0; i < n; i++)
    {
        minele = min(minele , arr[i]);
        maxele = max(maxele , arr[i]-minele);
    }
    return maxele;
}

int main(){
    int arr[] = {7,1,5,3,6,4};
    cout<<besttimeI(arr , 6)<<endl;
    cout<<besttime(arr , 6)<<endl;
}