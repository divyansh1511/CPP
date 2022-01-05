#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> stockspanpr(vector<int> v){
    int n = v.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(0);
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && v[i] >= v[s.top()])
        {
            s.pop();
        }
        ans[i] = s.empty() ? (i+1) : (i - s.top());
        s.push(i);
    }
    return ans;
}

int main(){
    vector<int> arr = {100,120,60,70,75,85,130};
    vector<int> output = stockspanpr(arr);
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
}