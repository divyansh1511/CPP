#include<bits/stdc++.h>
using namespace std;

int missing_number(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= n)
        {
            int pos = arr[i] - 1;
            if (arr[pos] != arr[i])
            {
                swap(arr[pos] , arr[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != (i+1))
        {
            return i+1;
        }
    }
    return n+1;
}

int main(){
    int arr[] = {3,4,-1 , 1};
    cout<<missing_number(arr , 4)<<endl;
}