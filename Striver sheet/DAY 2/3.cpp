//----------------merge 2 arr without using extra space---------------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge2arr(int arr1[] , int n , int arr2[] , int m){
    int i = 0,  j=0;
    while (i < n && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i] , arr2[j]);
            sort(arr2 , arr2+n);
        }
        else
        {
            i++;
        }
    }
}

int main(){
    int arr1[] = {1,2,3};
    int arr2[] = {2,4,5};
    merge2arr(arr1 , 3 , arr2 , 3);
    for (int i = 0; i < 3; i++)
    {
        cout<<arr1[i]<<" ";
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<arr2[i]<<" ";
    }
}