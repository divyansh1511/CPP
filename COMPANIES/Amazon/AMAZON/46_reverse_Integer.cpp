#include<bits/stdc++.h>
using namespace std;

int reverseinteger(int n){
    long int ans = 0;
    while (n != 0)
    {
        ans = ans*10 + n%10;
        n = n/10;
    }
    if (ans > INT_MAX || ans < INT_MIN)
    {
        return 0;
    }
    return ans;
}

int main(){

}