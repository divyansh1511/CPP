//ECLUIDS ALGO
#include<bits/stdc++.h>
using namespace std;

int gcd(int a , int b){
    if (b == 0)
    {
        return a;
    }
    return gcd(b , a%b);
}

int main(){
    cout<<gcd(10 , 15)<<endl;
    cout<<gcd(125 , 220)<<endl;
}