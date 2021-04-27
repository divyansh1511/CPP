#include<iostream>
using namespace std;

void selectionsort(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int index = i;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[index])
            {
                index = j;
            }
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
        
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