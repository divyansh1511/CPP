#include<iostream>
using namespace std;

void negativesort(int arr[] , int n){
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if(i != j){
                swap(arr[i] , arr[j]);
                j++;
            }
        }
    }
}

int main(){ 
    int arr[] = {1,-4,5,2,3,-7};
    negativesort(arr,6);

    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}