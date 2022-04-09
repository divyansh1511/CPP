#include<bits/stdc++.h>
using namespace std;

int dividenumber(int a , int b){
    if (a == INT_MIN && b == -1)
    {
        return INT_MAX;
    }
    int sign = ((a<0) ^ (b<0)) ? -1 : 1;
    a = abs(a);
    b = abs(b);
    int ans = 0;
    while (a >= b)
    {
        a -= b;
        ans++;
    }
    return ans*sign;
}

int main(){

}