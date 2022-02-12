#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[] , int n , int k){
    int i = 0, j = n-1;
    int mid = i + (j-i)/2;
    while (i < j)
    {
        if (arr[mid] == k)
        {
            return  mid;
        }
        else if (arr[mid] < k)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
        mid = i+(j-i)/2;
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout<<binarysearch(arr , 10 , 3)<<endl;
}