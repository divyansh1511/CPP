#include<bits/stdc++.h>
using namespace std;

int find_missing_number(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= n)
        {
            int a = arr[i]-1;
            if (arr[a] != arr[i])
            {
                swap(arr[a] , arr[i]);
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

}