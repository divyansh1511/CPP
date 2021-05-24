#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int sumofaodd(vector<int> arr){
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int contribution = ceil((i+1)*(n-i)/2.0);    //ceil
        ans += (contribution*arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<sumofaodd(arr)<<endl;
}