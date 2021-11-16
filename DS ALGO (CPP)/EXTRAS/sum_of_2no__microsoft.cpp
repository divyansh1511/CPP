//Sum of two numbers without using arithmetic operators 
#include<iostream>
using namespace std;

int sum(int a , int b){
    unsigned xor1 = a ^ b;
    unsigned carry = a&b;
    if (carry == 0)
    {
        return xor1;
    }
    else
    {
        return sum(xor1 , carry<<1);
    }
}

int main(){
    cout<<sum(30,54)<<endl;
}