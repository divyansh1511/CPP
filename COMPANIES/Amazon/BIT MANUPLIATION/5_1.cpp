#include<bits/stdc++.h>
using namespace std;

int reversebits(unsigned int a){
    int b = 0;
    for (int i = 0; i < 32; i++)
    {
        b <<= 1;
        b |= (a&1);
        a >>= 1;
    }
    return b;
}

int main(){

}