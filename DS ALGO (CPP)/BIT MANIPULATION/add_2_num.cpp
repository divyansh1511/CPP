#include<iostream>
using namespace std;

int add2num(int a , int b){
    while (b != 0)
    {
        unsigned carry = a&b;
        a = a^b;
        b = carry << 1;
    }
    return a;
}

int main(){
    cout<<add2num(10 , 20)<<endl;
}