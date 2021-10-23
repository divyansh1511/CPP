#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr){
    vector<int> ans;
    int n = arr.size();
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a = a^arr[i];
    }
    int right_bit = a & ~(a-1);
    int x,y;
    x = y = 0;
    for (int i = 0; i < n; i++)
    {
        if (right_bit & arr[i])
        {
            x = x ^ arr[i];
        }
        else
        {
            y = y ^ arr[i];
        }
    }
    ans.push_back(x);
    ans.push_back(y);
    sort(ans.begin() , ans.end());
    return ans;
}

int main(){
    vector<int> v = {1,2,3,4,3,2,1,5};
    vector<int> ans = solve(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
}