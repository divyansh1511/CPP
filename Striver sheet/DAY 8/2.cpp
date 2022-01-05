#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findplatform(int arr[] , int dep[] , int n){
    multiset<pair<int , char>> mp;
    for (int i = 0; i < n; i++)
    {
        mp.insert(make_pair(arr[i] , 'a'));
        mp.insert(make_pair(dep[i] , 'b'));
    }
    int result = 0;
    int count = 0;
    for (auto it : mp)
    {
        if (it.second == 'a')
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count > result)
        {
            result = count;
        }
    }
    return result;
}

int main(){
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findplatform(arr, dep, n);
}