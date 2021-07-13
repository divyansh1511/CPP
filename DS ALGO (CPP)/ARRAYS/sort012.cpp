#include<iostream>
using namespace std;

void Sort012(int arr[] , int n){
    int count0 = 0 , count1 = 0 , count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    
    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count0; i < (count0 + count1); i++)
    {
        arr[i] = 1;
    }
    for (int i = (count0+count1); i < n; i++)
    {
        arr[i] = 2;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int arr[] = {2,2,0,0,1,1,0};
    Sort012(arr , 7);
}