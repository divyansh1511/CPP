#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mincoins(int coins[] , int n , int V){
    sort(coins , coins+n , greater<int>());
    int count = 0;
    int i = 0;
    while (i < n)
    {
        if (V == 0)
        {
            break;
        }
        
        if (coins[i] <= V)
        {
            V = V-coins[i];
            count++;
        }
        else
        {
            i++;
        }   
    }
    return count;
}

int main(){
    int coins[] = {9,6,5,1};
    cout<<mincoins(coins , 4 , 11);
}