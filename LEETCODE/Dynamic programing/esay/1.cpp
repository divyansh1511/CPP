#include<bits/stdc++.h>
using namespace std;

vector<int> countbits(int n){
    vector<int> v(n+1 , 0);
    for (int i = 1; i <= n; i++)
    {
        v[i] = v[i/2] + i%2;
    }
    return v;
}

int main(){
    vector<int> v = countbits(5);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}