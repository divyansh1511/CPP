#include<bits/stdc++.h>
using namespace std;

int divide(int A , int B){
    if (A == INT_MAX && B == -1)
    {
        return INT_MAX;
    }
    long long int a = A , b = B;
    int sign = ((A < 0) ^ (B < 0)) ? -1 : 1;
    a = abs(A);
    b = abs(B);
    int ans = 0;
    while (a >= b)
    {
        a = a-b;
        ans++;
    }
    return ans*sign;
}

int main(){

}