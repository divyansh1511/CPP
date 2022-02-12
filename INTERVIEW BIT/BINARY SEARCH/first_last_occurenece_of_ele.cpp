#include<bits/stdc++.h>
using namespace std;

int firstoccurence(int arr[] , int n , int k){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    int ans = 0;
    while (i <= j)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            j = mid-1;
        }
        else if (arr[mid] < k)
        {
            i = mid+1;
        }
        else if(arr[mid] > k)
        {
            j = mid-1;
        }
        mid = i + (j-i)/2;
    }
    return ans;
}

int lastoccurence(int arr[] , int n , int k){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    int ans = 0;
    while (i <= j)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            i = mid+1;
        }
        if (arr[mid] < k)
        {
            i = mid+1;
        }
        else if(arr[mid] > k)
        {
            j = mid-1;
        }
        mid = i + (j-i)/2;
    }
    return ans;
}

int main(){
    int arr[] = {10,20,30,30,30,50};
    cout<<firstoccurence(arr , 6 , 30)<<endl;
    cout<<lastoccurence(arr , 6 , 30)<<endl;
}