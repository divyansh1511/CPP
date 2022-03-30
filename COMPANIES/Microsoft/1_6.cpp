#include<bits/stdc++.h>
using namespace std;

int findmissing(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= n && arr[i] > 0)
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
        if (arr[i] != i+1)
        {
            return i+1;
        }
    }
    return n+1;
}

int main(){

}