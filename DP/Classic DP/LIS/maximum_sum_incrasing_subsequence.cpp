#include<bits/stdc++.h>
using namespace std;

int maxsum(int arr[] , int n){
    int lis[n];
    for (int i = 0; i < n; i++)
    {
        lis[i] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j] && lis[i] < lis[j]+arr[i])
            {
                lis[i] = lis[j]+arr[i];
            }
        }
    }
    return *max_element(lis , lis+n);
}

int main(){
       
}