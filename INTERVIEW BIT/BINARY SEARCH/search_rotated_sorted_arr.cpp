#include<bits/stdc++.h>
using namespace std;

//-------------------------------1st-----------------------//

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

//--------------------------------2nd-------------------------------//

int searchrotated(int arr[] , int n , int k){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    while (i <= j)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        if (arr[0] <= arr[mid])
        {
            if (arr[mid] > k && k >= arr[0])
            {
                j = mid - 1;
            }
            else
            {
                i = mid+1;
            }
        }
        else
        {
            if (arr[mid] < k && k <= arr[n-1])
            {
                i = mid+1;
            }
            else
            {
                j = mid - 1;
            }
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
    cout<<searchrotated(arr , 7 , 3)<<endl;
}