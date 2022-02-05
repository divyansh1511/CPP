#include<iostream>
using namespace std;

void rotate(int arr[] , int n){
    int temp = arr[n-1];
    for (int i = n-1; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

//-------opti-----

void helper(int arr[] , int n){
    int i = 0 , j = n-1;
    while (i < j)
    {
        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
}

void rotateArr(int arr[] , int n , int k){
    helper(arr , n);
    helper(arr+n-k , k);
    helper(arr , n-k);
}

int main(){
    int arr[] = {1,2,3,4,5};
    rotate(arr , 5);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}