#include<bits/stdc++.h>
using namespace std;

bool ispossible(int arr[] , int n , int m , int mid){
    int studentcount = 1;
    int pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (pages + arr[i] <= mid)
        {
            pages += arr[i];
        }
        else
        {
            studentcount++;
            if (studentcount > m || arr[i] > m)
            {
                return false;
            }
            pages = arr[i];
        }
    }
    return true;
}

int bookAllocation(int arr[] , int n , int m){
    int s = 0 , e;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    e = sum;
    int mid = s + (e-s)/2;
    int ans = 0;
    while (s <= e)
    {
        if (ispossible(arr , n , m , mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){

}