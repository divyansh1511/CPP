// will be done by gap algo ..... not completed

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void mergewithoutspace(int arr1[] , int arr2[] , int n , int m){
    int i=0 , j=0;
    while (i < n && j<m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i] , arr2[j]);
            sort(arr2 , arr2+n);
        }
        i++;       
    }
}

int main(){
    int arr1[] = {10 , 12};
    int arr2[] = {5 , 18 ,20};
    mergewithoutspace(arr1 , arr2 , 2 ,3);
    for (int i = 0; i < 2; i++)
    {
        cout<<arr1[i]<<" ";
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<arr2[i]<<" ";
    }
    
}