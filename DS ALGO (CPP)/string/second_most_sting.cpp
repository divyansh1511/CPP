#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void firstmem(string arr[], int n){
    map<string , int> mp;
    for (int i = 0; i < n; i++)
    {
        string a = arr[i];
        mp[a]++;
    }
    auto penultimate = std::prev(mp.end(), 2);
    cout<<penultimate->first<<endl;
}

int main(){
    string arr[] = {"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};
    firstmem(arr , 6);
}