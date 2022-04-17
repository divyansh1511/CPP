#include<bits/stdc++.h>
using namespace std;

int merge(int arr[] , int temp[] , int low , int mid , int high){
    int count = 0;
    int i = low;
    int j = mid;
    int k = low;
    while (i <= mid-1 && j<=high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count += (mid-i);
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = temp[i++];
    }
    while (j <= high)
    {
        temp[k++] = temp[j++];
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
    return count;
}

int mergesort(int arr[] , int temp[] , int low , int high){
    int mid , count = 0;
    while (low < high)
    {
        count += mergesort(arr , temp , low , mid);
        count += mergesort(arr , temp , mid+1 , high);

        count += merge(arr , temp , low , mid , high);
    }
    return count;
}

int main(){

}