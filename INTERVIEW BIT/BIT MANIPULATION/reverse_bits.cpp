#include<bits/stdc++.h>
using namespace std;

unsigned int reverse_bits(unsigned int A){
    int b = 0;
    for (int i = 0; i < 32; i++)
    {
        b <<= 1;
        b |= (A&1);
        A >>= 1;
    }
    return b;
}

int main(){
    cout<<reverse_bits(3)<<endl;
}