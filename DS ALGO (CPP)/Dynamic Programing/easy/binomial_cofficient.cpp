#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binomial(int n , int k){
    if (k > n)
    {
        return 0;
    }
    if (k==0 || k==n)
    {
        return 1;
    }
    return binomial(n-1 , k-1) + binomial(n-1 , k);
}

int binomialdp(int n , int k){
    int C[k+1];
    memset(C , 0 , sizeof(C));

    C[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i , k); j > 0; j--)
        {
            C[j] = C[j] + C[j-1];
        }
    }
    return C[k];
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<binomial(n , k)<<endl;
    cout<<binomialdp(n , k)<<endl;
}