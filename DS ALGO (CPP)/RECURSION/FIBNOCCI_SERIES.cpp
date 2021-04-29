#include<iostream>
using namespace std;

int fibnoccinum(int n){
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fibnoccinum(n-1) + fibnoccinum(n-2);
}

int main(){
    int num;
    cout<<"enter the position "<<endl;
    cin>>num;

    cout<<fibnoccinum(num)<<endl;
}