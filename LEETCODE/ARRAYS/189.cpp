#include<bits/stdc++.h>
using namespace std;

void helper(int arr[] , int n){
    int i=0 , j = n-1;
    while (i < j)
    {
        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
}

void rotatearr(int arr[] , int n , int d){
    helper(arr , n);
    helper(arr+n-d , d);
    helper(arr , n-d);
}

int main(){
    int n , d;
    cin>>n>>d;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    rotatearr(arr , n , d);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}