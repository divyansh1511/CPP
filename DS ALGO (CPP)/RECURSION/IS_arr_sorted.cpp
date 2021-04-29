#include<iostream>
using namespace std;

bool isSorted(int arr[] , int size){
    if (size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    
    int smallerArray[size - 1];

    for (int i = 0; i < size; i++)
    {
        smallerArray[i-1] = arr[i];
    }
    bool issmallersorted = isSorted(smallerArray,size - 1);

    if (issmallersorted)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(){
    int arr[] = {1,2,8,4,5};
    cout<<isSorted(arr,5)<<endl;
}