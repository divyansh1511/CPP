#include<bits/stdc++.h>
using namespace std;

int findPivot(int arr[] , int n){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    while (i <= j)
    {
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            return mid;
        }
        if (arr[i] <= arr[mid])
        {
            i = mid + 1;
        }
        if (arr[mid] <= arr[j])
        {
            j = mid - 1;
        }
        mid = i + (j-i)/2;
    }
    return -1;
}

int binarysearch(int arr[] , int n , int k , int s , int e){
    int i = s , j = e;
    int mid = i + (j-i)/2;
    while (i <= j)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        if (arr[mid] < k)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
        mid = i + (j-i)/2;
    }
    return -1;
}

int main(){
    int arr[] = {5,6,7,1,2,3,4};
    int pivot = findPivot(arr , 7);
    int ans = binarysearch(arr , 7 , 3 , 0 , pivot-1);
    if (ans != -1)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<binarysearch(arr , 7 , 3 , pivot , 6)<<endl;
    }
    
}