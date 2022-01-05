#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string LCP(vector<string> a){
    int n = a.size();
    string ans = "";
    if (n == 0)
    {
        return "";
    }
    sort(a.begin() , a.end());
    string x = a[0];
    string y = a[n-1];
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == y[i])
        {
            ans = ans + x[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main(){
    vector<string> v = {"flower" , "flow" , "flllll"};
    cout<<LCP(v)<<endl;
}