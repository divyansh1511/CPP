#include<iostream>
using namespace std;

void bubblesort(int arr[] , int n){
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)         // here you can use j = 1
        {
            if (arr[j] > arr[j+1])          // change arr[j-1] and arr[j];
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    
}

int main(){
    int arr[] = {7,6,4,5,2,8,1};
    bubblesort(arr , 7);

    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}