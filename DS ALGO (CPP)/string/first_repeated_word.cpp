#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string firstmem(string arr[], int n){
    map<string , int> mp;
    for (int i = 0; i < n; i++)
    {
        string a = arr[i];
        if (mp[a] == 0)
        {
            mp[a] = 1;
        }
        else
        {
            return a;
        }
    }
    return "";
}

int main(){
    string arr[] = {"geek", "for", "geek", "for", "geek", "aaa"};
    cout<<firstmem(arr , 6)<<endl;
}