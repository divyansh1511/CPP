//--------------------find duplicate in arr------------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,1,4,5,6};
    sort(arr , arr + 7);
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] == arr[i+1])
        {
            cout<<arr[i]<<endl;
            break;
        }
    }
}