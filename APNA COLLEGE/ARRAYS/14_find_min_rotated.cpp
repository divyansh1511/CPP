#include<bits/stdc++.h>
using namespace std;

int findmin(int arr[] , int n){
    int low = 0 , high = n-1 , mid;
    while (low <= high)
    {
        mid = (low + high)/2;
        if (arr[low] <= arr[high])
        {
            return arr[low];
        }
        if (arr[mid] >= arr[low])
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return arr[low];
}

int main(){

}