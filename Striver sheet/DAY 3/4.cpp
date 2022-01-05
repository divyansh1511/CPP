#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> majorityele(int arr[] , int n){
    int a = 0 , b = 1 , cnt1 = 0 , cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a == arr[i])
        {
            cnt1++;
        }
        else if (b == arr[i])
        {
            cnt2++;
        }
        else if (cnt1 == 0)
        {
            a = arr[i];
            cnt1++;
        }
        else if (cnt2 == 0)
        {
            b == arr[i];
            cnt2++;
        }
    }
    cnt1 = cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            cnt1++;
        }
        else if (arr[i] == b)
        {
            cnt2++;
        }
    }
    vector<int> res;
    if (cnt1 > n/3)
    {
        res.push_back(a);
    }
    if (cnt2 > n/3)
    {
        res.push_back(b);
    }
    return res;
}

int main(){
    int arr[] = {3,2,3};
    vector<int> v  = majorityele(arr , 3);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}   