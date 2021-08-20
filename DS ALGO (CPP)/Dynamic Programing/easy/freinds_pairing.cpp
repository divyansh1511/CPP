#include<iostream>
using namespace std;

/*-----------------------O(N) O(N)---------------------------*/

int pairing(int n){
    int dp[n+1];
    for (int i = 0; i <= n; i++)
    {
        if (i<=2)
        {
            dp[i] = i;
        }
        else
        {
            dp[i] = dp[i-1] + (i-1)*dp[i-2];
        }
    }
    return dp[n];
}

/*-----------------------O(N) O(1)---------------------------*/

int pairingopti(int n){
    int a = 1 , b = 2 , c = 0;
    if (n <= 2)
    {
        return n;
    }
    for (int i = 3; i <= n; i++)
    {
        c += b + (i-1)*a;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    cout<<pairing(3)<<endl;
    cout<<pairingopti(3)<<endl;
}