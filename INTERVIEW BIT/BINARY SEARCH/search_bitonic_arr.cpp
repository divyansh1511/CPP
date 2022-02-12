#include<bits/stdc++.h>
using namespace std;

int findPeak(int arr[] , int n){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    while (i < j)
    {
        if (arr[mid] < arr[mid+1])
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
        mid = i + (j-i)/2;
    }
    return i;
}

int binarySearch(int arr[] , int start , int end , int k){
    int s = start , e = end;
    int mid = s + (e-s)/2;
    while (s <= e)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        if (arr[mid] < k)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int binarySearchBack(int arr[] , int start , int end , int k){
    int s = start , e = end;
    int mid = s + (e-s)/2;
    while (s <= e)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        if (arr[mid] < k)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    int arr[] = {1,3,5,20,17,12,2};
    int peak = findPeak(arr , 7);
    int n = 7;
    int ans = binarySearch(arr , 0 , peak-1 , 12);
    if(ans != -1){
        return ans;
    }
    else{
        return binarySearchBack(arr , peak , n-1 , 12);
    }
}