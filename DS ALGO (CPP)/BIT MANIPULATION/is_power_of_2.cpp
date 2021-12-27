#include<iostream>
using namespace std;

bool isPowerof2(int n){
    return n && (!(n & (n-1)));
}

int main(){
    cout<<isPowerof2(64)<<endl;
}