#include<bits/stdc++.h>
using namespace std;

bool permute(int arr1[] , int arr2[] , int n , int k){
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+n , greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] + arr2[i] < k)
        {
            return false;
        }
    }
    return true;
}

int main(){

}