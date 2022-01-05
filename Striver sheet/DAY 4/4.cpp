//------------------LARGEST SUBARR WITH SUM 0-------------------------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &A, int n)
{
    unordered_map<int , int> mp;
    int sum = 0;
    int maxlength = 0;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (A[i] == 0 && maxlength == 0)
        {
            maxlength = 1;
        }
        if (sum == 0)
        {
            maxlength = i+1;
        }
        if (mp.find(sum) != mp.end())
        {
            maxlength = max(maxlength , i-mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return maxlength;
}

int main(){
    vector<int> arr = { 15, -2, 2, -8, 1, 7, 10, 23 };
    cout<<maxLen(arr , arr.size())<<endl;
}