#include<bits/stdc++.h>
using namespace std;

void merge2arr(int arr1[] , int arr2[] , int n , int m){
    int i=0,j=0;
    while (i<n && j<m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i] , arr2[j]);
            sort(arr2 , arr2+n);
        }
        else
        {
            i++;
        }
    }
}

int main(){

}