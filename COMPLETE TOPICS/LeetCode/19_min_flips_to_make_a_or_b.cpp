#include<bits/stdc++.h>
using namespace std;

int minflips(int a , int b , int c){
    int t = a | b;
    int ans = 0;
    while (c != 0 || a != 0 || b != 0)
    {
        int m1 = a & 1;
        int m2 = b & 1;
        int k1 = t & 1;
        int k2 = c & 1;
        if(k1 == 0 && k2 == 1){
            ans += 1;
        }
        else if(k1 == 1 && k2 == 0){
            if(m1 == 1 && m2 == 1){
                ans += 2;
            }
            else{
                ans += 1;
            }
        }
        a >>= 1;
        b >>= 1;
        t >>= 1;
        c >>= 1;
    }
    return ans;
}

int main(){

}