#include<bits/stdc++.h>
using namespace std;

int firstoccurence(int arr[] , int n , int k){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    int ans = 0;
    while (i < j)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            j = mid-1;
        }
        if (arr[i] < k)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {10,20,30,30,30,50};
    cout<<firstoccurence(arr , 6 , 30)<<endl;
}