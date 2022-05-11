#include<bits/stdc++.h>
using namespace std;

void next_permutation(int arr[] , int n){
    int l , k;
    for (k = n-2; k >= 0; k--)
    {
        if (arr[k] > arr[k+1])
        {
            break;
        }
    }
    if(k < 0){
        reverse(arr , arr+n);
    }
    else
    {
        for (l = n-1; l >= k; l--)
        {
            if (arr[l] > arr[k])
            {
                break;
            }
        }
        swap(arr[l] , arr[k]);
        reverse(arr+k+1 , arr+n);
    }
}

int main(){

}