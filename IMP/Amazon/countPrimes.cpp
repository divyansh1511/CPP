#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countprimes(int n){
    if (n <= 0)
    {
        return 0;
    }
    vector<bool> v(n , true);
    int sq = sqrt(n);
    int ans = 0;
    v[1] = false;
    for (int i = 2; i <= sq; i++)
    {
        if (!v[i])
        {
            continue;
        }
        for (int j = i; i*j < n; j++)
        {
            v[i*j] = false;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if(v[i]){
            cout<<i<<" ";
            ans++;
        }
    }
    return ans;
}

int main(){
    cout<<countprimes(10)<<endl;
}