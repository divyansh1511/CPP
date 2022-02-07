#include<bits/stdc++.h>
using namespace std;

int findDuplicate(int arr[] , int n){
    vector<int> v(n , 0);
    for (int i = 0; i < n; i++)
    {
        v[arr[i]]++;
        if (v[arr[i]] > 1)
        {
            return arr[i];
        }
    }
    return -1;
}

int find_duplicate(int arr[] , int n){
    int xor1 = arr[0];
    int xor2 = 1;
    for (int i = 1; i < n; i++)
    {
        xor1 ^= arr[i];
    }
    for (int i = 2; i < n; i++)
    {
        xor2 ^= i;
    }
    int res;
    res = xor1^xor2;
    return res;
}

int main(){
    int arr[] = {1,2,3,4,2};
    cout<<find_duplicate(arr , 5)<<endl;
    cout<<findDuplicate(arr , 5)<<endl;
}