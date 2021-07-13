#include<iostream>
using namespace std;

void reversearr(int arr[] , int start ,int end){
    int i = 0;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    
}

int main(){
    int arr[] = {1,2,3,4,5};
    
    reversearr(arr , 0 , 4);

    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}