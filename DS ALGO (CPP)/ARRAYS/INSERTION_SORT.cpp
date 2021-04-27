#include<iostream>
using namespace std;

void insertionsort(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {6,5,4,3,2,1};
    insertionsort(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}