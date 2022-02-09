#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[] , int n){
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]){ 
            min_idx = j; 
        }
        swap(arr[min_idx], arr[i]); 
    } 
}

int main(){
    int arr[] = {5,3,8,7,4,9,58};
    selectionsort(arr, 7);

    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}