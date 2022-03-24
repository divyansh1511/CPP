#include<bits/stdc++.h>
using namespace std;

int search(int arr[] , int n , int key){
    int low = 0 , high = n-1;
    while (low < high)
    {
        int mid = (low + high)/2;
        if (arr[mid] > arr[high])
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    int rot = low;
    low = 0;
    high = n-1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        int realmid = (mid + rot)%n;
        if (arr[realmid] == key)
        {
            return realmid;
        }
        if (arr[realmid] < key)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {4,5,1,2,3};
    cout<<search(arr , 5 , 2)<<endl;
}