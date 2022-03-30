#include<bits/stdc++.h>
using namespace std;

int hotelbooking(int arr[] , int dep[] , int k ,  int n){
    sort(arr , arr+n);
    sort(dep , dep+n);
    for (int i = k; i < n; i++)
    {
        if (arr[i] < dep[i-k])
        {
            return false;
        }
    }
    return true;
}

int main(){
    
}