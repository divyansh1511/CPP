#include<bits/stdc++.h>
using namespace std;

void merge(int* arr , int s, int e){
    int mid = (s+e)/2;
    
    int len1 = mid-s+1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int index = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[index++];
    }
    index = mid+1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[index++];
    }
    
    int index1 = 0;
    int index2 = 0;
    index = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[index++] = first[index1++];
        }
        else
        {
            arr[index++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[index++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[index++] = second[index2++];
    }
    
}

void mergesort(int* arr , int s , int e){
    if (s >= e)
    {
        return;
    }
    int mid = (s+e)/2;
    mergesort(arr , s , mid);
    mergesort(arr , mid+1 , e);
    merge(arr , s , e);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    mergesort(arr , 0 , n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}