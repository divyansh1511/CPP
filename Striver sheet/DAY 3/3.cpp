#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int majorityele(int arr[], int n){
    unordered_map<int , int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if(mp[arr[i]] > n/2){
            return arr[i];
        }
    }
    return -1;
}   

int main(){
    int arr[] = {2,3,4,4,2,2,2};
    cout<<majorityele(arr , 7)<<endl;
}