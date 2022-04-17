#include<bits/stdc++.h>
using namespace std;

int pow(int x , int n){
    double res = 1;
    while (n)
    {
        if (n%2 == 0)
        {
            res = n>0 ? res*x : res/x;
        }
        x = x*x;
        n /= 2;
    }
    return res;
}

int main(){
    
}