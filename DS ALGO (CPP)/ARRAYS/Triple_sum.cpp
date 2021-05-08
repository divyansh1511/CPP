#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool triplesum(int arr[] , int n , int sum){
    sort(arr , arr+n);
    int j , k;
    for (int i = 0; i < n; i++)
    {
        j = i+1;
        k = n-1;
        while (j<k)
        {
            if (arr[i]+arr[j]+arr[k] == sum)
            {
                cout<<"triplet is : "<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                return true;
            }
            else if (arr[i]+arr[j]+arr[k] < sum)
            {
                j++;
            }
            else
            {
                k--;
            }
            
        }
        
    }
    return false;
}

int main(){
    int arr[] = {6,8,3,12,14,2,4};
    triplesum(arr , 7 , 25);
}