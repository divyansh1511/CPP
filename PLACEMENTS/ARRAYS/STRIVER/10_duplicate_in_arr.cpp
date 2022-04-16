#include<bits/stdc++.h>
using namespace std;

int duplicate_arr(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        if (arr[a-1] != arr[i])
        {
            swap(arr[a-1] , arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i+1)
        {
            return i+1;
        }
    }
    return n;
}

int main(){

}