#include<bits/stdc++.h>
using namespace std;

int pivotele(int arr[] , int n){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    while (i < j)
    {
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            return mid;
        }
        if (arr[i] <= arr[mid])
        {
            i = mid+1;
        }
        if(arr[mid] <= arr[j])
        {
            j = mid - 1;
        }
        mid = i + (j-i)/2;
    }
    return -1;
}

int main(){
    int arr[] = {5,6,7,1,2,3,4};
    cout<<pivotele(arr , 7)<<endl;
}